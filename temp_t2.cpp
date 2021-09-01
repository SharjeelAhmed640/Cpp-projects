#include <iostream>
#include <cstring>
#include <cmath>
/*Create a class template with two generic data types to print their addition. Show the results
for following types:
- int and double for example: (10,0.23) would print10.23
- char* and char*

o For example: (“Now”, “Then”) would print Now Then*/
using namespace std;

template<class T>
class Myclass{
    T data1,data2;
    public:
    void setdata(T const d1,T const d2)
    {
        data1=d1;
        data2=d2;
    }
    void sum()
    {
        cout<<data1+data2;
    }
};

int main()
{
    cout<<"Adding 10,0.25"<<endl;
    Myclass<float> obj1;
    obj1.setdata(float(10),0.25);
    obj1.sum();
    cout<<endl<<"Adding now, then"<<endl;
    Myclass<string> obj2;
    obj2.setdata("now","then");
    obj2.sum();
return 0;
}