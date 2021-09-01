#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
/*Write a program that has an abstract base class named Quad. This class should have four member
data variables (floats) representing side lengths and a pure virtual function Area. It should also
have a method for setting the data variables. Derive a class Rectangle from Quad and override the
Area method so that it returns the area of the Rectangle. Write a main function that creates a
Rectangle and sets the side lengths. Also write a top-level function that will take a parameter of
type Quad and return the value of the appropriate Area function.*/
class quad{
    protected:
    float l1,l2,l3,l4;
    public:
    double virtual area()=0;
    void setadata(float L1,float L2,float L3,float L4)
    {
        l1=L1;
        l2=L2;
        l3=L3;
        l4=L4;
    }

};
class rectangle:public quad{
    public:
    double  area(){
        return (l1*l2*l3*l4);
    }
};
template < class T=rectangle >
const double AREA(T q)
{
    return q.area();
}
int main()
{
    rectangle rec;
    rec.setadata(2,2,3,3);
    cout<<"area : "<<rec.area()<<endl;

    cout<<"area using top-level funtion : "<<AREA(rec)<<endl;

return 0;
}