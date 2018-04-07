#include <iostream>
#include <string>
#include <vector>
using namespace std;

//---------------------------
class BaseMenu;
class MenuItem;
class PopupMenu;

// 방문자의 인터페이스
struct IMenuVisitor
{
    virtual ~IMenuVisitor() {}

    virtual void visit(BaseMenu* p) = 0;
    virtual void visit(MenuItem* p) = 0;
    virtual void visit(PopupMenu* p) = 0;
    virtual void visit(PopupMenu* p) = 0;
};

struct IAcceptor
{
    virtual ~IAcceptor() {}
    virtual void accept(IMenuVisitor* p) = 0;
};
//-----------------------------------------------

class BaseMenu : public IAcceptor
{
    string title;
public:
    BaseMenu( string s) : title(s) {}
    void setTitle(string s) { title = s;}
    string getTitle() const { return title;}

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;
public:
    virtual void accept(IMenuVisitor* p)
    {
        p->visit(this);
    }

    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};


class PopupMenu : public BaseMenu
{
    vector<BaseMenu*> v;
public:
    PopupMenu( string s) : BaseMenu(s) {}



    void addMenu(BaseMenu* p) { v.push_back(p);}

    virtual void command()
    {
        while( 1 )
        {
            system("cls");

            int sz = v.size();

            for ( int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". << back " << endl;

            //------------------------------
            int cmd;
            cout << "choose menu >> ";
            cin >> cmd;

            if ( cmd < 1 || cmd > sz + 1 ) // 잘못된 입력
                continue;

            if ( cmd == sz + 1 )
                break;


            // 선택된 메뉴 실행..
            v[cmd-1]-> command(); // 핵심.. !
        }

    }
    virtual void accept(IMenuVisitor* p)
    {
        p->visit(this);

        for ( auto m : v)
            m->accept(p);
    }
};

class MenuTitleChangeVisitor : public IMenuVisitor
{
public:
    virtual void visit(BaseMenu* p) {}
    virtual void visit(MenuItem* p) {}
    virtual void visit(PopupMenu* p)
    {
        // popupmenu 의 타이틀을 변경한다.
        string s = p->getTitle();
        s = "[ " + s + " ]";

        p->setTitle(s);
    }
};

class EraseTitleChangeVisitor : public IMenuVisitor
{
public:
    virtual void visit(BaseMenu* p) {}
    virtual void visit(MenuItem* p) {}
    virtual void visit(PopupMenu* p)
    {
        p->setTitle("...");
    }
};

int main()
{
    PopupMenu* p1 = new PopupMenu("MENUBAR");

    p1->addMenu( new PopupMenu("SCREEN"));
    p1->addMenu( new PopupMenu("SOUND"));
    p1->addMenu( new MenuItem("power off", 11));

    //---------------------
    MenuTitleChangeVisitor mtcv;
    p1->accept(&mtcv);

    EraseTitleChangeVisitor etcv;
    p1->accept(&etcv);
    // 1. 메뉴 (복합객체)는 accept 가 필요
    // 2. 방문자 인터페이스 필요..

    p1->command();
}
























//
