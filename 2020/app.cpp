#include <iostream>
using namespace std;


class CWinApp; // 클래스 전방 선언.

CWinApp* g_app = 0;

class CWinApp
{
public:
    CWinApp()    { g_app = this;}
    virtual bool InitInstance() { return false; }
    virtual int  ExitInstance() { return false; }
    virtual int  Run()          { return 0; }
};

int main()
{
    if ( g_app->InitInstance() == true)
        g_app->Run();
    g_app->ExitInstance();
}

//-----------------------
// 라이브러리 사용자
// 1. CWinApp 의 파생 클래스 만들어야 한다.
// 2. 사용자 클래스를 전역객체 생성

class MyApp : public CWinApp
{
public:
    virtual bool InitInstance()
    {
        cout << "initialization" << endl;
        return true;
    }

    virtual int  ExitInstance()
    {
        cout << "finish" << endl;
        return 0;
    }
};
MyApp theApp;

// 1. 전역변수 생성자. 기반 클래스 생성자.
// 2. main 함수 실행.
































//
