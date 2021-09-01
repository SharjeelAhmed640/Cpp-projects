#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

template <class T1=int, class T2 = int >
void calculate(T1 x,T2 y)
{
    cout<<"X = "<<x<<endl
    <<"Y = "<<y<<endl;
    cout<<"Area of rectangle is : "<<x*y<<endl;
}

int main()
{
    {
    int a,b;
    cout<<"enter 1st number(int) : ";
    cin>>a;
    cout<<"enter 2nd number(int) : ";
    cin>>b;
    calculate(a,b);//int,int
    }
    {
    int a;
    float b;
    cout<<"enter 1st number(int) : ";
    cin>>a;
    cout<<"enter 2nd number(float) : ";
    cin>>b;
    calculate<int,float>(a,b);
    }
    {
    float a, b;
    cout<<"enter 1st number(float) : ";
    cin>>a;
    cout<<"enter 2nd number(float) : ";
    cin>>b;
    calculate<float,float>(a,b);
    }

return 0;
}