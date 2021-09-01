#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int min(int a, int b,int c)
{
    if(a<b && a<c)
    return a;
    else if(b<a && b<c)
    return b;
    else return c;
}
int min(int a, int b)
{
    if(a<b)
    return a;
    else 
    return b;
}
int main()
{
int a,b,c;
cout<<"enter 1st number : ";
cin>>a;
cout<<"enter 2nd number : ";
cin>>b;
cout<<"enter 3rd number : ";
cin>>c;


cout<<"lowest in "<<a<<","<<b<<","<<c<<" is : "<<min(a,b,c)<<endl;
cout<<"lowest in "<<a<<","<<b<<" is : "<<min(a,b)<<endl;
return 0;
}