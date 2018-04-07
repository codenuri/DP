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

// 함수 템플릿
template<typename T>
MemberAction<T>* action( void(T::*f)(), T* obj)
{
    return new MemberAction<T>( f, obj);
}

FunctionAction* action( void(*f)() )
{
    return new FunctionAction( f);
}


int main()
{
    Dialog dlg;
    //IAction* p1 = new FunctionAction(&foo);
    //IAction* p2 = new MemberAction<Dialog>(&Dialog::Close, &dlg);

    IAction* p1 = action(&foo);
    IAction* p2 = action(&Dialog::Close, &dlg);

    p1->Execute();
    p2->Execute();
}














/*
//---------------------------------------------
template<typename T> void square( T a) { return a * a; }

square<int>(3);
square(3);


list<int> s(10,3);

*/









//
