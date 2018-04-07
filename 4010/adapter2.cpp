#include <iostream>
#include <vector>
#include "TextView.h"
using namespace std;


class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
};

// TextView 클래스의 인터페이스를 도형편집기에 맞도록 수정

class Text : public TextView, public Shape
{
public:
    Text( string s) : TextView(s) {}

    virtual void Draw() { TextView::Show(); }
};

/*
class Text :  public Shape
{
    TextView tv;
public:
    Text( string s) : tv(s) {}

    virtual void Draw() { tv.Show(); }
};
*/

// 객체 어답터.
class ObjectAdapter :  public Shape
{
    TextView* pView; // 포인터가 핵심
public:
    ObjectAdapter( TextView* p) : pView(p) {}

    virtual void Draw() { pView->Show(); }
};

int main()
{
    vector<Shape*> v;

    TextView tv("world"); // 이미 존재 하던 객체..
    //v.push_back(&tv); // error.

    v.push_back( new ObjectAdapter(&tv));

    v.push_back( new Text("hello"));

    for ( auto p : v)
        p->Draw();
}








































//
