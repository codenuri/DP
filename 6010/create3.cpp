class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
    Rect() {}
public:
	friend class ShapeFactory;
};

class Circle : public Shape
{
    Circle() {}
public:
	friend class ShapeFactory;
};

class ShapeFactory
{
public:
	Shape* CreateShape( int type )
	{
		Shape* p = 0;
		switch( type )
		{
		case 1: p = new Rect; break;
		case 2: p = new Circle; break;
		}
		return p;
	}
};

int main()
{
	ShapeFactory factory;
	Shape* p = factory.CreateShape(1);

}














//
