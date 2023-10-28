#include "test.h"

using namespace std;

int toInt(const char* str, int* ptr)
{
	long L;
	char* e;

	errno = 0;
	L = strtol(str, &e, 10);

	if (!errno && *e == '\0')
		if (INT_MIN <= L && L <= INT_MAX)
		{
			*ptr = (int)L;
			return 0;
		}
		else
			return -1;
	else
		return -1;
}

void instruction(void)
{
    cout << "Instruction:" << endl;
    
    cout << "   t1: constructors;" << endl;
    cout << "   t2: =;" << endl;
    cout << "   t3: +=, -=, *=;" << endl;
    cout << "   t4: +, -, *;" << endl;
    cout << "   t5: ==, !=, <, <=, >, >=;" << endl;
    cout << "   t6: (), empty, lenght;" << endl;
    cout << "   t7: exceptions." << endl;
    //cout << "t: ;" << endl;
}

void test1()
{
    try
    {
        cout << "Default constructor:" << endl;

        set x;
        print(x);

        cout << "Constructor with parameters:" << endl;
        set y(6);
        print(y);

        cout << "Copy constructor (copy of previous):" << endl;
        set z(y);
        print(z);

        //cout << "Move constructor (second moves to new):" << endl;
        set w;
        w = move(y);
        //cout << "Second:" << endl;
        //print(y);
        //cout << "New:" << endl;
        //print(w);
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }
}

void test2()
{
    try
    {
        set x;
        x = 3;
        set y = x;

        cout << "set x = {3};" << endl;
        print(x);

        cout << "set y = x;" << endl;
        print(y);
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }
}

void test3()
{
    try
    {
        set x, y, z;

        for(int i = 0; i < 51; i++)
        {
            x += set(i);
        }

        print(x);

        z += x;

        for(int i = 0; i < 26; i++)
        {
            x -= set(2 * i);
        }
        print(x);
        print(z);

        z *= x;
        print(z);

        for(int i = 0; i < 26; i++)
        {
            y += set(3 * i);
        }
        print(y);

        y *= x;
        print(y);

        z *= set(0);
        print(z);
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }
}

void test4()
{
    try
    {
        set x, y;

        x = set(0) + set(3) + set(7) + set(13) + set(17) + set(23);
        y = set(1) + set(5) + set(6) + set(7)  + set(14) + set(15) + set(22) + set(23) + set(27) + set(32) + set(37);

        cout << "x:" << endl;
        print(x);
        cout << "y:" << endl;
        print(y);

        cout << "x + y:" << endl;
        print(x + y);
        cout << "x - y:" << endl;
        print(x - y);
        cout << "y - x:" << endl;
        print(y - x);
        cout << "x * y:" << endl;
        print(x * y);
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }
}

void test5()
{
    try
    {
        set x, y, z;

        for(int i = 0; i < 51; i++)
        {
            x += set(i);
        }

        cout << "x:" << endl;
        print(x);

        y = set(31) + set(3) + set(9) + set(14) + set(16) + set(32) + set(24) + set(20) + set(30);
        cout << "y:" << endl;
        print(y);

        z = y;
        cout << "z:" << endl;
        print(z);

        if(y < x)
            cout << "y is subset of x." << endl;
        if(y == z)
            cout << "y is equal to z." << endl;
        if (y != x)
            cout << "y is not equal to x." << endl;

        z = x - z;
        cout << "z:" << endl;
        print(z);

        if(x >= z)
            cout << "x contains z." << endl;
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }
}

void test6()
{
   /* try
    {
        set x, y;

        x = set(13) + set(17) + set(2) + set(24) + set(30) + set(1) + set(8) + set(19);
        y = set(3) + set(23) + set(29) + set(1) + set(6) + set(35) + set(4) + set(2) + set(33);
        cout << "x:" << endl;
        print(x);
        cout << "y:" << endl;
        print(y);

        set z;
        cout << "z:" << endl;
        print(z);

        cout << "List of x's members:" << endl;
        for(int i = 0; i < 35; i++)
            if(x(i))
                cout << i << ", ";
        cout << endl;

        if(z.isEmpty())
            cout << "z is empty." << endl;

        cout << "The lenght of y is " << y.lenght() << endl;
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }*/
   
   set A;
   for(int i = 1; i <= 1000; i++)
   {
        A += set(i);
        set B;
        B = A;
        set C(B);
        A = C;
        A = A;
   }
   
   for(int i = 1000; i >= 50; i--)
   {
       A -= set(i);
   }
   print(A);
}

/*void test7()
{
    try
    {
        set x(-1);

        set y = set(-1);

        set z;
        z += set(-1);
    }
    catch(int i)
    {
        if(i == -1)
            cout << "Wrong input parameters." << endl;
    }
}*/
