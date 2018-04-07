#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl;}

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl;}
};

//-----------------------

struct IAction
{
    virtual void Execute() = 0;
    virtual ~IAction() {}
};

class FunctionAction : public IAction
{
    typedef void(*FP)();

    FP handler;
public:
    FunctionAction(FP f) : handler(f) {}

    virtual void Execute() {handler();}
};

template<typename T>
class MemberAction : public IAction
{
    typedef void(T::*FP)();

    FP handler;
    T* target;
public:
    MemberAction(FP f, T* obj) : handler(f), target(obj) {}

    virtual void Execute() { (target->*handler)();}
};

int main()
{
    Dialog dlg;
    IAction* p1 = new FunctionAction(&foo);
    IAction* p2 = new MemberAction<Dialog>(&Dialog::Close, &dlg);

    p1->Execute(); // foo 실행
    p2->Execute(); // Dialog::Close


}













//
