#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> s = { 1,2,3,4,5,6,7,8,9,10};

    // 모든 요소를 2배로 만들고 싶다.
    // 방법1. 외부에서 직접 연산 수행.
    for ( auto& n : s )
        n = n * 2;

    // 방법 2. 멤버 함수로 기능을 제공
    s.twice_all_element();
    s.show_all_element();

    // 방법 3. 방문자 패턴을 사용한다.
    TwiceVisitor<int> tv; // 방문자.
    s.accept(&tv);

    ShowVisitor<int> sv; // 방문자.
    s.accept(&sv);

}





//
