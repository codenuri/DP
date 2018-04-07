#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl;}

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl;}
};


int main()
{
    void(*f1)()         = &foo;
    void(Dialog::*f2)() = &Dialog::Close;
}








//
