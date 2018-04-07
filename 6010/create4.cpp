class Shape
{
public:
	virtual ~Shape() {}

    virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
    virtual Shape* Clone() { return new Rect(*this);}
};
class Circle : public Shape
{
public:
    virtual Shape* Clone() { return new Circle(*this);}
};

int main()
{
	Shape* p = new Rect;

    Shape* p2 = p->Clone();

}









//
