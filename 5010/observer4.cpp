#include <iostream>
#include <vector>
using namespace std;


class Subject;

struct IGraph
{
    virtual void update(Subject*) = 0;

    virtual ~IGraph() {}
};





class Subject
{
    vector<IGraph*> v;
public:
    void attach(IGraph* p) { v.push_back(p);}
    void detach(IGraph* p) { }

    void notify()
    {
        for ( auto p : v)
            p->update(this);
    }
};

class Table : public Subject
{
    int data;
    int color;
public:
    int GetData() { return data;}

    void SetData(int d)
    {
        data = d;
        notify();
    }
};


class PieGraph : public IGraph
{
public:
    virtual void update(Subject* p)
    {
        // table 에 접근해서 data를 꺼내 온다.
        //int n = p->GetData(); // error. 캐스팅 필요.
        int n = static_cast<Table*>(p)->GetData();

        Draw(n);
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
    virtual void update(Subject* p)
    {
        int n = static_cast<Table*>(p)->GetData();

        Draw(n);
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
