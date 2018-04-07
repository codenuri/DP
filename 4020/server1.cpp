#include <iostream>
#include "ecourse_dp.hpp"
#include "ICalc.h"
using namespace std;
using namespace ecourse;

class Calc : public ICalc
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Calc calc;


int dispatch( int code, int x, int y )
{
	printf("[DEBUG] %d, %d, %d\n", code, x, y );

	switch( code )
	{
	case 1: return calc.Add( x, y);
	case 2: return calc.Sub( x, y);
	}
	return -1;
}

int main()
{
	ec_start_server("CalcService", dispatch);
}












//
