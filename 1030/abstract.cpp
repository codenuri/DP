
class Shape  // 추상 클래스.
{
public:
    virtual void Draw() = 0; // 순수 가상함수.

};
class Rect : public Shape
{
public:
};
virtual void Draw() {} // 구현부를 제공하면 추상 아님.

int main()
{
//    Shape  s; // error.
    Shape* p; // ok..

    Rect r; // Draw()구현이 없으면 error
}
