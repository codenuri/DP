#include <iostream>
#include <string.h>
using namespace std;

struct IEdit
{
    virtual void Draw() = 0;
    virtual ~IEdit() {}
};

struct IButton
{
    virtual void Draw() = 0;
    virtual ~IButton() {}
};

struct WinButton : public IButton { void Draw() { cout << "Draw WinButton" << endl;}};
struct GTKButton : public IButton{ void Draw() { cout << "Draw GTKButton" << endl;}};

struct WinEdit : public IEdit { void Draw() { cout << "Draw WinEdit" << endl;}};
struct GTKEdit : public IEdit { void Draw() { cout << "Draw GTKEdit" << endl;}};

//-------------------------------------
// Factory 의 공통의 기반 클래스
struct IFactory
{
    virtual IButton* CreateButton() = 0;
    virtual IEdit*   CreateEdit() = 0;
    virtual ~IFactory() {}
};

struct WinFactory : public IFactory
{
    IButton* CreateButton() { return new WinButton;}
    IEdit*   CreateEdit()   { return new WinEdit;}
};

struct GTKFactory : public IFactory
{
    IButton* CreateButton() { return new GTKButton;}
    IEdit*   CreateEdit()   { return new GTKEdit;}
};

int main(int argv, char** argc)
{
    IFactory* pFactory;
    if ( strcmp(argc[1], "Windows") == 0)
        pFactory = new WinFactory;
    else
        pFactory = new GTKFactory;


    IButton* pBtn = pFactory->CreateButton();
    pBtn->Draw();


}








//
