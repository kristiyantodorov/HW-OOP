#include<graphics.h> 
#include<iostream>

using namespace std;

template <class T>
T max (T arr[], int n)
{
	T result = arr[0];

	for (int i = 1; i < n; ++i)
	{
		result = max (result, arr[i]);
	}

	return result;
}

int main()
{
	int testi[] = {1,2,3,4,5,5,2,3,1};
	double testd[] = {1,2,6,23,4,5,5,2,3,1};
	char testd2[] = {1,2,6,23,4,5,5,2,3,1};

	cout << endl << "max I= " << max <int> (testi,9) << endl;
	cout << endl << "max D= " << max <double> (testd,9) << endl;
	cout << endl << "max D= " << max <char> (testd2,9) << endl;


	return 0;
}