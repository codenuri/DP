#include <iostream>
#include <functional>
using namespace std;

void foo() { cout << "foo" << endl;}
void goo(int n) { cout << "goo : " << n << endl;}

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl;}
};

int main()
{
    function<void()> f;
    f = &foo;
    f();    // foo 호출

    Dialog dlg;

    f = bind(&Dialog::Close, &dlg); // action(&Dialog::Close, &dlg)
    f(); // dlg.Close()

    f = bind(&goo, 5);
    f(); // goo(5)

}












//
