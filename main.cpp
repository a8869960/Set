#include "set.h"
#include "test.h"


using namespace std;

int main(int ac, char* av[])
{
    if (ac == 1 || ac > 2)
    {
        instruction();
        return -1;
    }
    
    try{
    
    int n;
    
    if(strcmp("all", av[1]) == 0)
    {
        cout << "TEST #1" << endl;
        test1();
        cout << "TEST #2" << endl;
        test2();
        cout << "TEST #3" << endl;
        test3();
        cout << "TEST #4" << endl;
        test4();
        cout << "TEST #5" << endl;
        test5();
        cout << "TEST #6" << endl;
        test6();
        //cout << "TEST #7" << endl;
        //test7();
        
        return 0;
    }
    else if (toInt(av[1], &n) == -1)
    {
        instruction();
        return -1;
    }
    
    if(0 >= n || n >= 7)
    {
        cout << "No such test." << endl;
        return -1;
    }
    
    switch(n)
    {
        case 1:
            test1();//
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        case 4:
            test4();
            break;
        case 5:
            test5();
            break;
        case 6:
            test6();
            break;
        //case 7:
            //test7();
           // break;
    }
    } catch(int i)
    {
     if(i == -1)
         cout << "Exception" << endl;
     return -1;
    }
    
    
    
	
	return 0;
}

