#include "menu.hpp"

// 메뉴 메세지를 처리하려면 아래 인터페이스를 정의 해야 한다.
struct IMenuListener
{
    virtual void doCommand( int id) = 0;
    virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
    int id;
    IMenuListener* pListener = 0;

public:
    void setListener(IMenuListener* p) { pListener = p;}
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        // 변하는 것을 다른 클래스로..!
        if ( pListener != 0 )
            pListener->doCommand( id );
    }
};

class Dialog : public IMenuListener
{
public:
    virtual void doCommand(int id)
    {
        //cout << "Dialog doCommand" << endl;
        switch( id )
        {
        case 11: cout << "11" << endl; break;
        case 12: cout << "12" << endl; break;
        }
    }
};

int main()
{
    Dialog dlg;
    MenuItem m1( "Add Student " , 11);
    MenuItem m2( "Remove Student " , 12);

    m1.setListener(&dlg);
    m2.setListener(&dlg);


    m1.command();
    m2.command();
}














//
