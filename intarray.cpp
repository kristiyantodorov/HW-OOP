#include <iostream>
#include <cassert>

using namespace std;

class IntArray
{

private:

	int *arr;
	int size;



public:

	
	IntArray (const IntArray &original)
	{
		arr=NULL;
		copy (original);
	}

	IntArray ()
	{
		size = 0;
		arr = NULL;
	}

	void toEnd(int newelement)
	{
		int* newbuf = new int[size+1];
		for(int i=0;i<size;i++)
		{
			newbuf[i]=arr[i];
			
		}
		newbuf[size]=newelement;
		size++;

		delete arr;

		arr=newbuf;

	}
	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout << arr[i]<<" ";
		}
		cout << endl;
	}
	
	int& operator[](int index)
	{
		assert(index>=0 && index<=size);
		return arr[index];
	}

	void copy (const IntArray& a)
	{
	  int* newbuf = new int [a.size];
	  for(int i=0; i<a.size; i++)
	  {
	  	newbuf[i]=a.arr[i];
	  }	
	  delete arr;
	  arr=newbuf;
	  size=a.size;
	}

	IntArray& operator=(const IntArray& original)
	{
		if (this != &original)
		{
			copy(original);
		}
		
		return *this;
	}

	IntArray operator + (const IntArray other)
	{
		IntArray result;
		for (int i = 0; i < min(size,other.size); ++i)
		{
			result.toEnd(arr[i]+other.arr[i]);
		}
		return result;
	}

	~IntArray()
	{
		delete [] arr;
	}


};


int main ()
{
	IntArray a;

	a.toEnd (1);
	a.toEnd (2);
	a.toEnd (3);
	a.toEnd (4);

	a[2]=100;

	a.print();

	cout << endl;
	
	IntArray b;

	b=a;

	b=b+a;

	b.print();

	return 0;
}