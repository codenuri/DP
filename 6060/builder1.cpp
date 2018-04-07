#include <iostream>
#include <string>
using namespace std;

// 입학 지원서
using Application = string; // class Application {}


// 지원서 만드는 클래스
class Director
{
    string name = "HONG";
    string phone = "010-111-1111";
    string address = "SEOUL KANGNAMGU";
public:
    Application construct()
    {
        Application app;
        app += name + "\n";
        app += phone + "\n";
        app += address + "\n";
        return app;
    }
};

int main()
{
    Director d;
    // 전화, 이름 입력...
    Application app = d.construct();
    cout << app << endl;
}






//
