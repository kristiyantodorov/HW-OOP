#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
	string name;
	int age;
	double weight;
protected:
	Animal(string _n="No name ", int _a=0, double _w=0)
	{
		name=_n;
		age=_a;
		weight=_w;
	}

	virtual void make_sound() = 0;
	virtual void grow() = 0;

	string getName()const
	{
		return name;
	}

	int getAge()const
	{
		return age;
	}

	double getWeight()const
	{
		return weight;
	}

	void setName(string _n)
	{
		name=_n;
	}

	void setAge(int _a)
	{
		age=_a;
	}

	void setWeight(double _w)
	{
		weight=_w;
	}

public:
	void print()
	{
		cout<<name<<endl;
		cout<<age<<endl;
		cout<<weight<<endl;
	}
};

class Cat : public Animal
{
public:
	Cat (string _n="No name ", int _a=0, double _w=0) : Animal(_n, _a, _w){}

	void make_sound()
	{
		cout<<"Meow!\n";
	}

	void grow()
	{
		int a=getAge();
		setAge(a+1);
		double w = getWeight();
		setWeight(w + 2);
	}
};

class Dog : public Animal
{
public:
	Dog (string _n="No name ", int _a=0, double _w=0) : Animal(_n, _a, _w){}

	void make_sound()
	{
		cout<<"Woof!\n";
	}

	void grow()
	{
		int a=getAge();
		setAge(a+1);
		double w = getWeight();
		setWeight(w + 2);
	}

	
};

class Crocodile : public Animal
{
public:
	Crocodile (string _n, int _a, double _w) : Animal(_n, _a, _w){}

	void make_sound()
	{
		cout<<"I'm a crocodile and I don't make sounds at all!\n";
	}

	void grow()
	{
		int w = getWeight();
		setWeight(w + 4);
	}	
};

int main()
{
	Animal* zoo[100];

	zoo[0]=new Crocodile("Baaa", 200, 100);

	zoo[0]->print();

	/*for (int i = 0; i < 3; ++i)
	{
		cout<<"Enter "D" for dog, "C" for cat or "R" for crocodile\n";
		cin>>ch;
		switch (ch)
		{
			case 'D': 
		}
	}*/

	return 0;
}