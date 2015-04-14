#include <iostream>
#include <assert.h>

using namespace std;

class IntArray{
private:
	int size = 0;
	int* arr;
public:
	//constructor
	IntArray(){
		size = 0;
		arr = NULL;
	}

	
	//destructor
	~IntArray(){
		delete [] arr;
	}

	
	//copy values
	void copy(const IntArray& original)
	{
		size = original.size;

		int* newbuf = new int[size];

		for (int i = 0; i < size; i++)
		{
			newbuf[i] = original.arr[i];
		}
		
		delete arr;

		arr = newbuf;
	}

	
	//copy-constructor
	IntArray(const IntArray& original)
	{
		arr = NULL;

		size = original.size;

		copy(original);
	}


	void toEnd(int newelement)
	{
		int* newBuf = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			newBuf[i] = arr[i];
		}

		newBuf[size] = newelement;
		size++;

		delete arr;
		arr = newBuf;
	}
	

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	int getAt(int index)
	{
		assert(index >= 0 && index <= size - 1);

		return arr[index];
	}


	void setAt(int index, int newValue)
	{
		arr[index] = newValue;
	}


	bool isMember(int num)
	{
		int i = 0;
		while (num != arr[i] && i<size)
		{
			i++;
			if (arr[i]==num)
			{
				return true;
			}
		}
		return false;
	}


	int sum()
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}


	bool equals(const IntArray& a)
	{
		int i = 0;
		bool flag = true;

		while (i<size && arr[i]==a.arr[i])
		{
			i++;
		}

		if (i<size)
		{
			flag = false;
		}

		return flag;
	}


	void concat(const IntArray& a)
	{
		int* newbuf = new int[size + a.size];
		for (int i = 0; i < size; i++)
		{
			newbuf[i] = arr[i];
		}
		
		for (int i = 0; i < a.size; i++)
		{
			newbuf[size + i] = a.arr[i];
		}

		size = size + a.size;
		
		delete [] arr;

		arr = newbuf;
	}


	void removeAt(int index)
	{
		int* newbuf = new int[size - 1];
		
		for (int i = 0; i < index; i++)
		{
			newbuf[i] = arr[i];
		}
		
		for (int i = index+1; i < size; i++)
		{
			newbuf[i - 1] = arr[i];
		}

		size--;
		delete[] arr;
		arr = newbuf;

	}
};

int main(){
	IntArray a;

	a.toEnd(0);
	a.toEnd(0);
	a.toEnd(7);

	IntArray b(a);

	a.concat(b);

	a.Print();

	return 0;
}