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
// -style 옵션에 상관없이 무조건 windows 스타일 사용
class WinDialog
{
public:
    void Init()
    {
        WinButton* pBtn = new WinButton;
        WinEdit*   pEdit = new WinEdit;

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
};

class GTKDialog
{
public:
    void Init()
    {
        GTKButton* pBtn = new GTKButton;
        GTKEdit*   pEdit = new GTKEdit;

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
};
int main()
{
    WinDialog dlg;
    dlg.Init();
}




















//
