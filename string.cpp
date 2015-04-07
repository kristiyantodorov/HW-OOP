#include <iostream>
#include <cstring>

using namespace std;

class String
{

public:
	char *buf;

	String(char *s = "Hello")
	{

		buf = new char[strlen(s)+1];
		strcpy(buf, s);

	}

	~String()
	{
		delete buf;
	}

	void print()
	{
		cout << buf << endl;
	}

	String(const String& str)
	{
		buf = new char[strlen(str.buf) + 1];
		strcpy(buf, str.buf);
	}

	void concat(String s)
	{

		//buf, s.buf
		char *newbuf = new char[strlen(buf) + strlen(s.buf) + 1];

		strcpy(newbuf, buf);

		strcat(newbuf, s.buf);

		delete buf;
		buf = newbuf;

	}

	void Remove(char c)
	{
	    int count = 0;

	    for(int p=0;p<strlen(buf);p++)
        {
            if(buf[p]==c) count++;
        }

	    char *newbuf=new char[strlen(buf)+1-count];

	    int j=0;

        for(int i=0;i<strlen(buf)+1;i++)
        {
            if(buf[i]!=c)
            {
                newbuf[j]=buf[i];
                j++;
            }
        }

        delete buf;
        buf=newbuf;
    }


    void symbolConcat(char c)
    {
        char* newbuf=new char[strlen(buf)+1+1];

        for(int i=0; i<strlen(buf);i++)
        {
            newbuf[i]=buf[i];
        }

        newbuf[strlen(buf)]=c;
        newbuf[strlen(buf)+1]='\0';

        delete buf;
        buf=newbuf;
    }

};



int main()
{
	String s1("Hello "),
		   s2("world!");

	s1.print();
	s2.print();

	s1.concat(s2);
	s1.print();

	s1.symbolConcat('l');
	s1.print();

	s1.Remove('l');
	s1.print();

	s2=s1;

	s2.print();

	cout << "\n\n\n";

    system("pause");

	return 0;
}
