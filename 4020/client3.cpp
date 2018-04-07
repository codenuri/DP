#include <iostream>
#include "ecourse_dp.hpp"
#include "ICalc.h"
using namespace std;
using namespace ecourse;

class Calc : public ICalc
{
    int server;
public:
    Calc() { server = ec_find_server("CalcService");    }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

int main()
{
    Calc* pCalc = new Calc;

	cout << pCalc->Add(1, 2) << endl;
    cout << pCalc->Sub(10, 8) << endl;
}









//
