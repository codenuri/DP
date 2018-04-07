#include <iostream>
using namespace std;

struct Object
{
    virtual ~Object() {}
};
// 모든 클래스는 object 로 부터 파생되어야 한다.

class Dialog : public Object{};
class Point : public Object{};
class Rect : public Object{};
class Integer : public Object
{
    int value;
public:
    Integer(int n) : value(n) {}
}


struct Node
{
    Object*   data;
    Node* next;
    Node( Object* d, Node* n) : data(d), next(n) {}
};

class slist
{
    Node* head = 0;
public:
    void push_front(Object* n) { head = new Node(n, head);}
    Object*  front()           { return head->data;}
};

int main()
{
    slist s;

    s.push_front(new Point);
    s.push_front(new Point);

    s.push_front ( 10 ); // error
    s.push_front ( new Integer(10) ); // ok.

//    Point* p = s.front();
    Point* p = static_cast<Point*>(s.front());

//    s.push_front( new Dialog );


//    int n = s.front();
}









//
