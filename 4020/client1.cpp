#include <iostream>
#include "ecourse_dp.hpp"
using namespace std;
using namespace ecourse;

int main()
{
	int server = ec_find_server("CalcService");

	cout << "server : " << server << endl;

	int ret = ec_send_server(server, 1, 10, 20);

	cout << ret << endl; // 30


}
