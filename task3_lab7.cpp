#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class shape{
protected:
float lenght , breadth,height;
    public:
    virtual void area()
    {
        cout<<"Volume is : "<<lenght*breadth*height<<endl;
    }
};
class sphere:public shape{
 
    public:
    sphere(float x)
    {
        this->lenght=x;
        
        if(x<0)
        lenght=0.0;
       
    }
    void setdata(float const x)
    {
         lenght=x;
        
        if(x<0)
        lenght=0.0;
       
    }
    void area()
    {
        cout<<endl<<"Area of rectangular box is "<<3.142*lenght*lenght<<endl;
    }
};


class cylinder:public shape{
    public:
    cylinder(float x,float z)
    {
        lenght=x;
       
        height=z;
        if(x<0)
        lenght=0.0;
        
        if(z<0.0)
        height=0.0;
    }
    void setdata(float const x,float const z)
    {
        lenght=x;
       
        height=z;
        if(x<0)
        lenght=0.0;
        
        if(z<0.0)
        height=0.0;
    }
    void area()
    {
        cout<<endl<<"Area of rectangular box is "<<(3.142)*lenght*lenght*height<<endl;
    }
};



int main()
{
shape * ptr=new sphere(5);
//ptr->setdata(5);
ptr->area();
return 0;
}