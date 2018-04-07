#include "ecourse_dp.hpp"
#include "ICalc.h"
using namespace ecourse;

class Calc : public ICalc
{
    int server;
    int count = 0;
public:
    Calc()  { server = ec_find_server("CalcService");    }
    ~Calc()  { cout << "~Calc" << endl; }

    void AddRef()  { ++count;}
    void Release() { if ( --count == 0 ) delete this; }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

extern "C" __declspec(dllexport)
ICalc* CreateCalc()
{
    return new Calc;
}






//
