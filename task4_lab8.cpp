#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class multiplication{
    public:
    int multiply(int x,int y){
        return x*y;
    }
    int multiply(int x,int y,int z){
        return x*y*z;
    }
    float multiply(float x, float y)
    {
        return x*y;
    }
    float multiply(float x, float y,float z)
    {
        return x*y*z;
    }
};


int main()
{
int a,b,c;
float x,y,z;
cout<<"Enter 1st int : "; cin>>a;
cout<<"Enter 2nd int : "; cin>>b;
cout<<"Enter 3rd int : "; cin>>c;
cout<<"Enter 1st float : "; cin>>x;
cout<<"Enter 2nd float : "; cin>>y;
cout<<"Enter 3rd float : "; cin>>z;
multiplication m;
cout<<a<<" X "<<b<<" = "<<m.multiply(a,b)<<endl
<<a<<" X "<<b<<" X "<<c<<" = "<<m.multiply(a,b,c)<<endl
<<x<<" X "<<y<<" = "<<m.multiply(x,y)<<endl
<<x<<" X "<<y<<" X "<<z<<" = "<<m.multiply(x,y,z);
return 0;
}