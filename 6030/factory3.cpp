#include <iostream>
#include <vector>
#include <map>
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

    static Shape* Create() { return new Rect;}
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Rect" << endl;}

    static Shape* Create() { return new Circle;}
};


// new Circle;
// Circle::Create()




class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)

    typedef Shape* (*CREATOR)();

    map<int, CREATOR> create_map;

public:
    void Register( int type, CREATOR f )
    {
        create_map[type] = f;
    }

    Shape* CreateShape(int type )
    {
        Shape* p = 0;
        auto ret = create_map.find( type );
        if ( ret == create_map.end() )
            return 0;
        p = create_map[type]();

        return p;
    }
};



int main()
{
    ShapeFactory& factory = ShapeFactory::getInstance();

    // 공장에 제품을 등록한다.
    factory.Register( 1, &Rect::Create);
    factory.Register( 2, &Circle::Create);

    //factory.ShowProduct();

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
