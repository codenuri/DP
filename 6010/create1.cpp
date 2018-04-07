class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
};
class Circle : public Shape
{
public:
};

int main()
{
	Rect r;

	Shape* p = new Rect;

}
