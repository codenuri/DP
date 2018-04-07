#include <iostream>
#include <vector>
#include "TextView.h"
using namespace std;



class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
};

// TextView 를 도형편집기에서 사용하기 위해
// 인터페이스 변경(함수 이름 변경.)
class Text : public TextView, public Shape
{
public:
    Text( string s) : TextView(s) {}

    virtual void Draw() { TextView::Show(); }
};




class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Draw Rect" << endl;}
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Rect" << endl;}
};

int main()
{
    vector<Shape*> v;
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Text("hello") );

    for ( auto p : v)
        p->Draw();

}
























//
















//
