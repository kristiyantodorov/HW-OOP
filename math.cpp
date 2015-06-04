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

class Min : public Formula
{
private:
	Formula *x, *y;
public:
	Min(Formula* a, Formula* b)
	{
		x=a;
		y=b;
	}

	int value()
	{
		if (x->value() < y->value())
		{
			return x->value();
		}
		return y->value();
	}

	~Min()
	{
		delete x;
		delete y;
	}
};

class Max : public Formula
{
private:
	Formula *x, *y;
public:
	Max(Formula* a, Formula* b)
	{
		x=a;
		y=b;
	}

	int value()
	{
		if (x->value() > y->value())
		{
			return x->value();
		}
		return y->value();
	}

	~Max()
	{
		delete x;
		delete y;
	}
};

class LessThan : public Formula
{
private:
	Formula *x, *y;
public:
	LessThan(Formula* a, Formula* b)
	{
		x=a;
		y=b;
	}

	int value()
	{
		if(x->value() < y->value()) return 1;
		return 0;
	}

	~LessThan()
	{
		delete x;
		delete y;
	}
	
};

class GreaterThan : public Formula
{
private:
	Formula *x, *y;
public:
	GreaterThan(Formula* a, Formula* b)
	{
		x=a;
		y=b;
	}

	int value()
	{
		if(x->value() > y->value()) return 1;
		return 0;
	}

	~GreaterThan()
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

	if (c == 'M')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new Max (leftOperand, rightOperand);
	}

	if (c == 'm')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new Min (leftOperand, rightOperand);
	}

	if (c == '<')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new LessThan (leftOperand, rightOperand);
	}

	if (c == '>')
	{
		Formula *leftOperand = parse();
		Formula *rightOperand = parse();

		return new GreaterThan (leftOperand, rightOperand);
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
	cout<<endl;

	Formula* parsedTree = parse(); 

	cout<<"=======================\n";

	cout<<"Parsed tree value: "<<parsedTree->value()<<endl;

	return 0;
}