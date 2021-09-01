#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class circle{
    float radius;
    public:
    circle(float radius=0.0)
    {
        this->radius=radius;
    }
    float getArea();
    float getPerimeter()
    {
        return (2*3.142*radius);
    }
};
float circle :: getArea(){
    return (3.142*(pow(radius,2)));
}
int main(){
float radius;
cout<<"Enter the radius : ";
cin>>radius;
circle c1(radius);
cout<<endl<<"Area : "<<c1.getArea()
<<endl<<"Perimeter : "<<c1.getPerimeter();
 
return 0;
}