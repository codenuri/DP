#include <iostream>
#include <vector>
#include "Singleton.hpp"
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
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

class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)
public:
    Shape* CreateShape(int type )
    {
        Shape* p = 0;
        if      ( type == 1 ) p = new Rect;
        else if ( type == 2 ) p = new Circle;

        return p;
    }
};

int main()
{
    ShapeFactory& factory = ShapeFactory::getInstance();
    vector<Shape*> v;

    while( 1 )
    {
        int cmd;
        cin >> cmd;

        //
        if ( cmd >=1 && cmd <= 5 )
        {
            Shape* p = factory.CreateShape(cmd);

            if ( p != 0 )
                v.push_back( p );
        }
        else if ( cmd == 9 )
        {
            for ( auto p : v )
                p->Draw(); // 다형성
        }
    }
}
































//
