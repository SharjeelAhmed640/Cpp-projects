#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
template <class T>
class complex{
    T x,y;
    public:
    complex(T a=0,T b=0)
    {
        x=a; y=b;
    }
    void show_data()
    {
        cout<<x<<"+"<<y<<"i"<<endl;
    }
    complex operator +(complex p)
    {
        complex temp;
        temp.x=x+p.x;
        temp.y=y+p.y;
        return temp; 
    }

};
int main(){
complex<int> c1(1,2),c2(1,3),c3,c4;
c3=c1+(c2);
c3.show_data();
c4=c3.operator+(c1);
c4.show_data();

 
return 0;
}