#include <iostream>
using namespace std;

template<typename T> struct Node
{
    T   data;
    Node* next;
    Node( const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> class slist
{
    Node<T>* head = 0;
public:
    void push_front(const T& n) { head = new Node<T>(n, head);}
    T  front()                  { return head->data;}
};

int main()
{
    slist<Point> s2;

    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    //s.push_front( new Dialog);

    int n = s.front();
}









//
