#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class A{
    protected:
    int a;
    public:
    A(int a)
    {
        this->a=a;
    }
    //A(){}
};
class B:virtual public A{
    protected:
    int b;
    public:
    B(int a,int b):A(a)
    {
        this->b=b;
    }
};
class C:virtual public A{
    protected:
    int c;
    public:
    C(int a,int c):A(a)
    {
        this->c=c;
    }
};
class D:public B,public C{
    protected:
    int d;
    public:
    D(int a,int b ,int c, int d):B(a,b),C(a,c),A(a)
    {
        this->d=d;
    }
    void display()
    {
        cout<<a<<endl<<b<<endl<<c<<endl<<d;
    }
};
class E:public D{
    int e;
    public:
    E(int a,int b ,int c, int d,int e):D(a,b,c,d),A(a)
    {
        this->e=e;
    }
    void display()
    {
        cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e;
    }
};
int main()
{
E e(1,2,3,4,5);
e.display();
return 0;
}