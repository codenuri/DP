#include <iostream>
#include <vector>
using namespace std;


struct IGraph
{
    virtual void update(int) = 0;

    virtual ~IGraph() {}
};


class Table
{
    vector<IGraph*> v;

    int data;
public:
    void attach(IGraph* p) { v.push_back(p);}
    void detach(IGraph* p) { }


    void SetData(int d)
    {
        data = d;

        for ( auto p : v)
            p->update(data);
    }
};




class PieGraph : public IGraph
{
public:
    virtual void update(int n)
    {
        Draw(n); // 그래프를 다시 그린다.
    }
    void Draw(int n)
    {
        cout << "Pie Graph : ";

        for ( int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
    }
};

class BarGraph : public IGraph
{
public:
    virtual void update(int n)
    {
        Draw(n); // 그래프를 다시 그린다.
    }
    void Draw(int n)
    {
        cout << "Bar Graph : ";

        for ( int i = 0; i < n; i++)
            cout << "+";
        cout << endl;
    }
};

int main()
{
    BarGraph bg;
    PieGraph pg;

    Table t;
    t.attach( &bg);
    t.attach( &pg);

    while( 1 )
    {
        int n;
        cin >> n;
        t.SetData(n);
    }
}




















//
