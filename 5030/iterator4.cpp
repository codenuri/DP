#include <iostream>
using namespace std;

template<typename T> struct Node
{
    T   data;
    Node* next;
    Node( const T& d, Node* n) : data(d), next(n) {}
};




template<typename T> class slist_iterator
{
    Node<T>* current = 0;
public:
    inline slist_iterator( Node<T>* p = 0) : current(p) {}

    inline slist_iterator& operator++()
    {
         current = current->next;
         return *this;
    }
    inline T&  operator*() { return current->data; }
};
// ++p, *p



template<typename T> class slist
{
    Node<T>* head = 0;
public:
    slist_iterator<T> begin()
    {
        return slist_iterator<T>( head);
    }

    void push_front(const T& n) { head = new Node<T>(n, head);}
    T  front()                  { return head->data;}
};








template<typename T> void Show( T p, T p2 )
{
    do
    {
        cout << *p << endl;
    } while( ++p  != p2);
}

int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    int* p1 = x;
    Show( p1, x+10);

    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);

    slist_iterator<int> p = s.begin();

    cout << *p << endl;
    ++p;
    cout << *p << endl; // 30
}









//
