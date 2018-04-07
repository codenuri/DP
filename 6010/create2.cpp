class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
    Rect() {}  // private 생성자.
public:
    static Shape* Create() { return new Rect;}
};
class Circle : public Shape
{
    Circle() {}
public:
    static Shape* Create() { return new Circle;}
};

// 도형을 만들어서 그림을 그리는 함수
//void CreateAndDraw(string s)
//void CreateAndDraw(int type)
void CreateAndDraw(Shape* (*f)() )
{
    // ..
//    new s;
//    if ( type == 1 ) new Rect;

    Shape* p = f();
    p->Draw();
}


int main()
{
    CreateAndDraw(&Rect::Create );
    //CreateAndDraw("Rect");

	//Shape* p = Rect::Create();

}









//
