// cont3.cpp => iterator1.cpp
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
    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);

    SlisEnumerator<int>* p = s.GetEnumerator();

    int n = p->GetObject(); // 40
    p->MoveNext(); //

    int n2 = p->GetObject(); // 50



}









//
