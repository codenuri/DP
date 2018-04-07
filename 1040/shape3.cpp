#include <iostream>
#include <vector>
using namespace std;

class Shape
{
protected:
    // 변하는 것을 가상함수로 뽑아낸다.
    virtual void DrawImp()
    {
        cout << "Draw Shape" << endl;
    }

public:
    // final : 파생 클래스가 재정의 할수 없게 한다.
    virtual void Draw() final
    {
        cout << "mutex lock" << endl;

        DrawImp();
        cout << "mutex unlock" << endl;
    }


    virtual Shape* Clone() { return new Shape(*this);}
};



class Rect : public Shape
{
public:
    virtual void DrawImp() { cout << "Draw Rect" << endl;}



    virtual Shape* Clone() { return new Rect(*this);}
};

class Circle: public Shape
{
public:
    virtual void DrawImp() { cout << "Draw Circle" << endl;}
    virtual Shape* Clone() { return new Circle(*this);}
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
            v.push_back( v[k]->Clone() );
        }
        else if ( cmd == 9 )
        {
            for ( auto p : v)
                p->Draw();
        }
    }

}
































//
