#include <iostream>
#include <cmath>

using namespace std;

class Figure
{
protected:
	double x,y;
public:
	virtual void print (int i) = 0;

	virtual double perimeter () = 0;

	virtual double read () = 0;

	virtual double surface()
	{
		return -1;
	}
};

class Rectangle : public Figure
{
private:
	double a,b;
public:
	Rectangle(double _x=0, double _y=0, double _a=0, double _b=0) :a(_a), b(_b)
	{
		x=_x;
		y=_y;
	}
 
 	double read()
 	{
 		cout<<"Enter x: ";
 		cin>>x;
 		cout<<"Enter y: ";
 		cin>>y;
 		cout<<"Enter a: ";
 		cin>>a;
 		cout<<"Enter b: ";
 		cin>>b;
 		cout<<endl;
 	}

 	double perimeter()
 	{
 		return 2*a+2*b;
 	}

 	void print(int i)
 	{
 		cout<<"Figure "<<i+1<<"(Rectangle):\n";
 		cout<<"	Surface: "<<surface()<<endl;
 		cout<<"	Perimeter: "<<perimeter()<<endl;
 	}

	double surface()
	{
		return a*b;
	}
};

class Triangle : public Figure
{
private:
	double a,b,c;
public:
	Triangle(double _x=0, double _y=0, double _a=0, double _b=0, double _c=0) : a(_a), b(_b), c(_c)
	{
		x=_x;
		y=_y;
	}

	double read()
 	{
 		cout<<"Enter x: ";
 		cin>>x;
 		cout<<"Enter y: ";
 		cin>>y;
 		cout<<"Enter a: ";
 		cin>>a;
 		cout<<"Enter b: ";
 		cin>>b;
 		cout<<"Enter c: ";
 		cin>>c;
 		cout<<endl;
 	}

 	double perimeter()
 	{
 		return a+b+c;
 	}

 	void print(int i)
 	{
 		cout<<"Figure "<<i+1<<"(Triangle):\n";
 		cout<<"	Surface: "<<surface()<<endl;
 		cout<<"	Perimeter: "<<perimeter()<<endl;
 	}


	double surface()
	{
		double p=(a+b+c)/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
};


class Circle : public Figure
{
private:
	double r;
public:
	Circle(double _r=0, double _x=0, double _y=0) : r(_r)
	{
		x=_x;
		y=_y;
	}

	double read()
 	{
 		cout<<"Enter x: ";
 		cin>>x;
 		cout<<"Enter y: ";
 		cin>>y;
 		cout<<"Enter r: ";
 		cin>>r;
 		cout<<endl;
 	}

 	double perimeter()
 	{
 		return 2*3.14*r;
 	}

 	void print(int i)
 	{
 		cout<<"Figure "<<i+1<<"(Circle):\n";
 		cout<<"	Surface: "<<surface()<<endl;
 		cout<<"	Perimeter: "<<perimeter()<<endl;
 	}

	double surface()
	{
		return r*r*3.14;
	}
};

double sumSurfaces(Figure& f1, Figure& f2)
{
	return f1.surface() + f2.surface();
}

int main()
{
	Figure* figures[3];
	char type;

	for (int i = 0; i < 3; ++i)
	{
		cout<<"Enter type of figure ('r' for rectangle, 'c' for circle and 't' for triangle)\n";
		cin>>type;
		switch(type)
		{
			case 'r': 
			{
				figures[i]=new Rectangle;
				figures[i]->read();
				break;
			}

			case 'c':
			{
				figures[i]=new Circle;
				figures[i]->read();
				break;
			}

			case 't':
			{
				figures[i]=new Triangle;
				figures[i]->read();
				break;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		figures[i]->print(i);
	}

	return 0;
}