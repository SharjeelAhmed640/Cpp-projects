//filename: arrayaddder.cpp
//Modify this program to overload subtraction operator and insertion operator
#include <iostream>
using namespace std;

class A
{
public:
    int a;
};
istream &operator>>( istream &o, A &obj)
{
    o>>obj.a;
}
ostream &operator<<(ostream &o,const A &obj)
{
    cout<<"Value of a is : "<<obj.a<<endl;
}
int main()
{
   
A a;
cin>>a;
cout<<a;
    return 0;
}