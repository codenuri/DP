/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : Design Pattern 
* MODULE     : ecourse_DP.hpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#ifndef ECOURSE_CO_KR
#define ECOURSE_CO_KR

#if _MSC_VER > 1000
#pragma  once
#endif

#ifdef UNICODE
#undef _UNICODE
#undef UNICODE
#endif

#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <tchar.h>
#include <map>
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
using namespace std;

namespace ecourse
{
	namespace module
	{
#ifdef _WIN32
#define IOEXPORT __declspec(dllexport)
#else
#define IOEXPORT
#endif

		void* ec_load_module(string path)
		{
			return reinterpret_cast<void*>(LoadLibraryA(path.c_str()));
		}
		void ec_unload_module(void* p)
		{
			FreeLibrary((HMODULE)p);
		}
		void* ec_get_function_address(void* module, string func)
		{
			return reinterpret_cast<void*>(GetProcAddress((HMODULE)module, func.c_str()));
		}
	}
	namespace file
	{
		typedef int(*PFENUMFILE)(string, void*);

		void ec_enum_files(string path, string filter, PFENUMFILE f, void* param)
		{
			BOOL b = SetCurrentDirectory(path.c_str());

			if (b == false)
			{
				cout << "[DEBUG] " << path.c_str() << " directory does not exit" << endl;
				return;
			}
			WIN32_FIND_DATA wfd = { 0 };
			HANDLE h = ::FindFirstFile(filter.c_str(), &wfd);
			do
			{
				if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && !(wfd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
				{
					if (f(wfd.cFileName, param) == 0) break;
				}
			} while (FindNextFile(h, &wfd));

			FindClose(h);
		}
	}

	namespace ipc
	{
		typedef int(*IPC_SERVER_HANDLER)(int, int, int);

		IPC_SERVER_HANDLER _proxyServerHandler;

		LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			if (msg >= WM_USER)
				return _proxyServerHandler(msg - WM_USER, wParam, lParam);

			switch (msg)
			{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			}
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}

		HWND MakeWindow(string name, int show)
		{
			HINSTANCE hInstance = GetModuleHandle(0);
			WNDCLASS wc;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
			wc.hCursor = LoadCursor(0, IDC_ARROW);
			wc.hIcon = LoadIcon(0, IDI_APPLICATION);
			wc.hInstance = hInstance;
			wc.lpfnWndProc = WndProc;
			wc.lpszClassName = _T("First");
			wc.lpszMenuName = 0;
			wc.style = 0;

			RegisterClass(&wc);

			HWND hwnd = CreateWindowEx(0, _T("First"), name.c_str(), WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);

			ShowWindow(hwnd, show);
			return hwnd;
		}


		void ProcessMessage(IPC_SERVER_HANDLER handler)
		{
			_proxyServerHandler = handler;
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		//------------------------------------------------------------------

		void ec_start_server(string name, IPC_SERVER_HANDLER handler, int show = SW_HIDE)
		{
			printf("[DEBUG MESSAGE] %s Server Start...\n", name.c_str());

			MakeWindow(name, show);
			ProcessMessage(handler);
		}

		int ec_find_server(string name)
		{
			HWND hwnd = FindWindow(0, name.c_str());

			if (hwnd == 0)
			{
				printf("[DEBUG] ???? : %s Server?? ????? ???????.\n", name.c_str());
				return -1;
			}
			return (long long)hwnd;
		}

		int ec_send_server(long long serverid, int code, int param1, int param2)
		{
			return SendMessage((HWND)serverid, code + WM_USER, param1, param2);
		}

	}
	using namespace file;
	using namespace module;
	using namespace ipc;
}

#endif	// ECOURSE_CO_KR
