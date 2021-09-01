#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class Area{
    double area,length;
    public:
    Area(double l=0)
    {
        length=l;
        if(l<0)
        length=0;
    }
    void calArea()
    {
        area=length*length;
    }
    Area operator+(Area obj)
    {
        Area temp;
        temp.area=this->area+obj.area;
        return temp;
    }
    void display()
    {
        cout<<"Area : "<<area<<endl;
    }
};

int main()
{
    double l;
cout <<"Enter the length of 1st square : "; cin>>l;
Area square1(l);
square1.calArea();
cout <<"Enter the length of 2nd square : "; cin>>l;
Area square2(l);
square2.calArea();
Area sum;
sum=square1+square2;
cout<<"Square 1 : "; square1.display();
cout<<"Square 2 : "; square2.display();
cout<<"Sum of area of both Squares  : "; sum.display();

return 0;
}