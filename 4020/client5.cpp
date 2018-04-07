#include <iostream>
#include "ecourse_dp.hpp"
#include "ICalc.h"
using namespace std;
using namespace ecourse;

typedef ICalc* (*F)();

int main()
{
    // 동적 모듈 load
    void* addr = ec_load_module("CalcProxy.dll");

    F f = (F)ec_get_function_address(addr, "CreateCalc");

    ICalc* pCalc = f(); // CreateCalc()
    pCalc->AddRef();
    //---------------------------------------

	cout << pCalc->Add(1, 2) << endl;
    cout << pCalc->Sub(10, 8) << endl;

    pCalc->Release();
}











//
