#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class Perimeter{
    float len,wid;
    double per;
    public:
    friend class Print;
    Perimeter(float l,float w)
    {
        len=l;
        wid=w;
    }
    void cal()
    {
        per=2*(len+wid);
    }
};
class Print{
    public:
    void printdata(Perimeter const & obj)
    {
        cout<<"Perimeter : "<<obj.per<<endl;
    }
};
int main()
{
float l,w;
cout<<"Enter lenght of rectangle : "; cin>>l;
cout<<"Enter width of rectangle : "; cin>>w;
Perimeter rectangle(l,w);
rectangle.cal();
Print print;
print.printdata(rectangle);

return 0;
}