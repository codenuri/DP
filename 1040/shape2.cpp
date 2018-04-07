#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    int type;
    virtual void Draw() { cout << "Draw Shape" << endl;}

    // 자신의 복사본을 만드는 가상함수.
    virtual Shape* Clone() { return new Shape(*this);}
};







class Rect : public Shape
{
public:
    Rect() { type = 1;}
    virtual void Draw() { cout << "Draw Rect" << endl;}

    virtual Shape* Clone() { return new Rect(*this);}
};

class Circle: public Shape
{
public:
    Circle() { type = 2;}
    virtual void Draw() { cout << "Draw Circle" << endl;}

    virtual Shape* Clone() { return new Circle(*this);}
};



class Triangle : public Shape
{
public:
    virtual void Draw() { cout << "Draw Triangle" << endl;}
};

int main()
{
    vector<Shape*> v;

    while(1)
    {
        int cmd;
        cin >> cmd;

        if      ( cmd == 1 ) v.push_back(new Rect);
        else if ( cmd == 2 ) v.push_back(new Circle);



        else if ( cmd == 8 )
        {
            cout << "index >> ";
            int k;
            cin >> k;

            // k 번째 도형의 복사본을 v에 추가한다.

            v.push_back( v[k]->Clone() ); // 다형성.

/*
            // k 번째 도형의 복사본을 v에 추가한다.
            switch( v[k]->type )
            {
            case 1:  break;
            case 2:  break;
            }
            */

        }


        else if ( cmd == 9 )
        {
            for ( auto p : v)
                p->Draw();  // 다형성
        }
    }

}
































//
