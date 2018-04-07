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

            cout << sz + 1 << ". 상위 메뉴로 " << endl;

            //------------------------------
            int cmd;
            cout << "메뉴를 선택하세요 >> ";
            cin >> cmd;

            if ( cmd < 1 || cmd > sz + 1 ) // 잘못된 입력
                continue;

            if ( cmd == sz + 1 )
                break;


            // 선택된 메뉴 실행..
            v[cmd-1]-> command(); // 핵심.. !
        }

    }
};




int main()
{
    PopupMenu pm("화면설정");
}














//
