#include <iostream>
#include <cassert>

using namespace std;

class Formula
{
public:
	virtual int value () = 0;
	virtual ~Formula(){}
};

class Id : public Formula
{
private:
	int x;

public:
	Id (int a)
	{
		x=a;
	}

	int value()
	{
		return x;
	}
};

class Sum : public Formula
{
	Formula *x, *y;

public:
	Sum(Formula* a, Formula* b)
	{
		x=a;
		y=b;
	}


	int value()
	{
		return x->value() + y->value();
	} 

	~Sum()
	{
		delete x;
		delete y;
	}
};

class Product : public Formula
{
	Formula *x, *y;
	
public:
	Product(Formula* a, Formula* b)
	{
		x=a;
		y=b;
	}

	int value()
	{
		return (x->value()) * (y->value());
	} 

	~Product()
	{
		delete x;
		delete y;
	}
};

Formula* parse()
{
	char c = cin.get();

	if (c >= '0' && c <= '9')
	{
		return new Id (c-'0');
	}

	if (c == '+')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new Sum (leftOperand, rightOperand);
	}

	if (c == '*')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new Product (leftOperand, rightOperand);
	}

	assert(false);
	return NULL;
}

int main ()
{

	Formula *f = new Sum (new Product 
		     					(new Id (2), new Id (4)),
		     			  new Sum 
		     			        (new Id (5), new Id (7)));

	Formula* parsedTree = new 

	cout << "Value=" << f->value()<<endl;

}