#include <iostream>
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
struct GTKButton : public IButton { void Draw() { cout << "Draw GTKButton" << endl;}};

struct WinEdit : public IEdit { void Draw() { cout << "Draw WinEdit" << endl;}};
struct GTKEdit : public IEdit { void Draw() { cout << "Draw GTKEdit" << endl;}};

//---------------------------------------------------

class BaseDialog
{
public:
    void Init()
    {
        IButton* pBtn = CreateButton();
        IEdit*   pEdit = CreateEdit();

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
    virtual IButton* CreateButton() = 0;
    virtual IEdit*   CreateEdit() = 0;
};


class WinDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() { return new WinButton;}
    virtual IEdit* CreateEdit()    { return new WinEdit;}
};

class GTKDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() { return new GTKButton;}
    virtual IEdit* CreateEdit()   { return new GTKEdit;}
};

int main()
{
    WinDialog dlg;
    dlg.Init();
}




















//
