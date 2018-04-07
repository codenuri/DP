#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}
    string getTitle() const { return title;}

    virtual BaseMenu* getSubMenu(int idx)
    {
        //throw "unsupported function.."
        return 0;
    }
    void addMenu(BaseMenu* p)
    {
         throw "unsupported function..";
     }

    virtual void command() = 0;
};



class MenuItem : public BaseMenu
{
    int id;
public:
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

            cout << sz + 1 << ". 상위 메뉴로" << endl;

            //------------------------------
            int cmd;
            cout << "메뉴를 선택하세요 >> ";
            cin >> cmd;

            if ( cmd < 1 || cmd > sz + 1 )
                continue;

            if ( cmd == sz + 1 )
                break;



            v[cmd-1]-> command();
        }

    }
    BaseMenu* getSubMenu(int idx)
    {
        return v[idx];
    }
};

int main()
{
    PopupMenu* menubar = new PopupMenu("mebuBar");
    PopupMenu* pm1 = new PopupMenu("화면설정");
    PopupMenu* pm2 = new PopupMenu("소리설정");
    MenuItem*  m1  = new MenuItem("정보 확인", 11);
    menubar->addMenu( pm1 );
    menubar->addMenu( pm2 );
    menubar->addMenu( m1 );
    pm1->addMenu( new MenuItem("해상도변경", 21));
    pm1->addMenu( new MenuItem("명암 변경", 22));
    pm2->addMenu( new MenuItem("음량 조절", 31));

    BaseMenu* p = menubar->getSubMenu(1)->getSubMenu(0);

    menubar->getSubMenu(1)->addMenu( new MenuItem("AA", 100));


    // 시작하려면
    menubar->command();

}














//
