#include<cmath>
#include<iostream>
#include<string>
using namespace std;
class point{
    int x,y;
    public:
    point(int a=0, int b=0)
    {
        x=a;
        y=b;
    }
    void display();
    friend float disbtpoints(point,point);
};
void point :: display()
{
    cout<<"the points are ("<<x<<","<<y<<")"<<endl;
}
float disbtpoints(point A,point B)
{
  return sqrt ( pow(A.x - B.x,2)+pow(A.y - B.y,2));
}
int main(){
   point p1,p2(2,0);
   p1.display();
   p2.display();
   float distance=disbtpoints(p1,p2);
   cout<<"Distance b/w two points are : "<<distance<<endl;
   return 0;
}