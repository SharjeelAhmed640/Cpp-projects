#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class shape{
    public:
    virtual void area()=0;
};
class rectangle:public shape{
    float lenght,breadth,height;
    public:
    rectangle(float x,float y,float z)
    {
        lenght=x;
        breadth=y;
        height=z;
        if(x<0)
        lenght=0.0;
        if(y<0.0)
        breadth=0.0;
        if(z<0.0)
        height=0.0;
    }
    void setdata(float const x,float const y,float const z)
    {
        lenght=x;
        breadth=y;
        height=z;
        if(x<0)
        lenght=0.0;
        if(y<0.0)
        breadth=0.0;
        if(z<0.0)
        height=0.0;
    }
    void area()
    {
        cout<<endl<<"Area of rectangular box is "<<lenght*breadth*height<<endl;
    }
};


class cylinder:public shape{
    float radius,height;
    public:
    cylinder(float x,float z)
    {
        radius=x;
       
        height=z;
        if(x<0)
        radius=0.0;
        
        if(z<0.0)
        height=0.0;
    }
    void setdata(float const x,float const z)
    {
        radius=x;
       
        height=z;
        if(x<0)
        radius=0.0;
        
        if(z<0.0)
        height=0.0;
    }
    void area()
    {
        cout<<endl<<"Area of rectangular box is "<<(3.142)*radius*radius*height<<endl;
    }
};


class cube:public shape{
    float height;
    public:
    cube(float z)
    {
        
       
        height=z;
        
        
        if(z<0.0)
        height=0.0;
    }
    void setdata(float const x,float const z)
    {
        
       
        height=z;
        
        
        if(z<0.0)
        height=0.0;
    }
    void area()
    {
        cout<<endl<<"Area of rectangular box is "<<height*height*height<<endl;
    }
};
int main()
{
float radius,height,length,breadth;
cout<<"Area of rectangle "<<endl;
cout<<"enter lenght : "; cin>>length;
cout<<"enter breadth : "; cin>>breadth;
cout<<"enter height : "; cin>>height;
rectangle R(length,breadth,height);
R.area();
cout<<endl<<"Area of cube"<<endl;
cout<<"Enter length of sides : "; cin>>length;
cube C(length);
C.area();
cout<<endl<<"Area of cylinder"<<endl;
cout<<"enter radius : "; cin>>radius;
cout<<"enter lenght : "; cin>>length;
cylinder cy(radius,length);
cy.area();
return 0;
}