#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

class simplecal{
    protected:
    float a,b,res;
    public:
    void SETDATA(float A=0 ,float B=0)
    {
        a=A; b=B;
    }
    void add()
    {
        cout<<"the sum of "<<a<<" and "<<b<<" is "<<a+b<<endl;
    }
    void sub()
    {
        cout<<"the difference of "<<a<<" and "<<b<<" is "<<a-b<<endl;
    }
    void mul()
    {
        cout<<"the product of "<<a<<" and "<<b<<" is "<<a*b<<endl;
    }
    void div()
    {
        cout<<"After dividing  "<<a<<" and "<<b<<" ressult is "<<a/b<<endl;
    }

};
class scientifccal : public simplecal{
    protected:
    int c;
    public:
    void setdata(int C)
    {
        c=C;
    }
    void squarroot()
    {
        cout<<"the root of "<<c <<" is "<<sqrt(c)<<endl;
    }
    void SINE()
    {
        cout<<"Sin of "<<c<<" is "<<sin(c)<<endl;
    }

};
int main(){
   scientifccal C;
   C.setdata(16.0);
   C.SINE(); C.squarroot();
   C.SETDATA(10.0  ,  9.0);
   C.add();
   C.mul();
   return 0;
}