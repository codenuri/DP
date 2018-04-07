#include <iostream>
#include <vector>
using namespace std;

class Table
{
    int data;
public:
    void SetData(int d) { data = d;  }
};

class PieGraph
{
public:
    void Draw(int n)
    {
        cout << "Pie Graph : ";

        for ( i = 0; i < n; i++)
            cout << "*";
    }
};

int main()
{
}




















//
