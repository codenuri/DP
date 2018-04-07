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

struct RegisterShape
{
    RegisterShape( int type, Shape*(*f)() )
    {
        ShapeFactory& factory = ShapeFactory::getInstance();

        factory.Register(type, f);
    }
};
//RegisterShape rs(1, &Rect::Create);



class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Draw Rect" << endl;}

    static Shape* Create() { return new Rect;}
    static RegisterShape rs;
};
RegisterShape Rect::rs( 1, &Rect::Create);


// 모든 도형이 지켜야 하는 규칙을 매크로로 제공
#define DECLARE_SHAPE( classname )                  \
    static Shape* Create() { return new classname;}      \
    static RegisterShape rs;

#define IMPLEMENT_SHAPE( type, classname )                \
    RegisterShape classname::rs(type, &classname::Create);


class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Rect" << endl;}

    DECLARE_SHAPE( Circle )
};
IMPLEMENT_SHAPE( 2, Circle )


class Triangle : public Shape
{
public:
    virtual void Draw() { cout << "Triangle Rect" << endl;}

    DECLARE_SHAPE( Triangle )
};
IMPLEMENT_SHAPE( 3, Triangle )




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
