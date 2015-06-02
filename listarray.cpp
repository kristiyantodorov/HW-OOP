#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;


struct ListNode
{
	int data;
	ListNode* next;

	ListNode (int _d=0, ListNode *_n=NULL)
	{
		data = _d;
		next = _n;
	}


};

class ListIntArray
{

private:

	ListNode *first;

public:

	
	ListIntArray (const ListIntArray &original)
	{
		first=NULL;
		copy(original);
	}

	ListIntArray ()
	{
		first = NULL;
	}

	void copy(const ListIntArray& other)
	{
		if (other.first!=NULL)
		{
			ListNode* other_crr = other.first;
			first = new ListNode;
			ListNode* crr = first;
			crr->data = other_crr->data;
			while(other_crr->next)
			{
				other_crr = other_crr->next;
				crr->next = new ListNode(other_crr->data, NULL);
				crr=crr->next;
			}
		}
	}

	void push (int newelement)
	{

		first = new ListNode(newelement,first);
	}

	void toEnd(int newelement)
	{
		if(first==NULL) 
		{
			first=new ListNode;
			first->data=newelement;
		}
		else 
		{
			ListNode* crr=first;
			while (crr->next)
			{
				crr=crr->next;
			}
			crr->next=new ListNode(newelement,NULL);
		}
	}

	void print()
	{
		if (first != NULL)
		{
			ListNode* crr = first;
			while (crr)
			{
				cout<<crr->data<<" ";
				crr=crr->next;
			}
			cout<<endl;
		}
		else cout<<"Empty list!\n";
	}


	int& operator [] (int index)
	{	
		if(index==0) return first->data;
		else
		{
			ListNode* crr=first;
			for (int i = 0; i < index; ++i)
			{
				crr=crr->next;
			}
			return crr->data;
		}
	}


	~ListIntArray()
	{
		deleteList();
	}


	ListIntArray operator + (const ListIntArray& other)
	{
		ListIntArray arr;
		arr.copy(*this);
		ListNode* other_crr = other.first;
		while(other_crr)
		{
			arr.toEnd(other_crr->data);
			other_crr = other_crr->next;
		}
		return arr;
	}

	void deleteList()
	{
		ListNode* crr = first;
		while(crr)
		{
			first = first->next;
			delete crr;
			crr=first;
		}
	}

	ListIntArray& operator = (const ListIntArray other)
	{
		deleteList();
		copy(other);
	}
};



int main ()
{
	ListIntArray list1, list2;

	list1.toEnd(1);
	list1.toEnd(2);
	list1.toEnd(3);
	list1.toEnd(4);
	list1.toEnd(5);
	list2.toEnd(6);
	list2.toEnd(7);
	list2.toEnd(8);
	list2.toEnd(9);
	list2.toEnd(10);

	list1.print();

	list2.print();

	list2=list1;

	list2.print();

	return 0;
}



