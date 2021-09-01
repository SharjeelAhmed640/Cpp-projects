#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class operatorExample{
    int x,y;
    int score;
    public:
    operatorExample(int a, int b,int c=0)
    {
        x=a;y=b;score=c;
    }
    void display()
    {
        cout<<endl<<x<<" + "<<y<<"i"<<endl<<"score = "<<score<<endl;
    }
    void operator ++()
    {
        ++score;
    }
    void operator ++(int){
        score++;
    }
    operatorExample(){}
    operatorExample operator +(operatorExample const &obj){
        operatorExample temp;
            temp.x=this->x+obj.x;
            temp.y=this->y+obj.y;
            temp.score=this->score+obj.score;
            return temp;
    }
};
int main()
{
operatorExample obj1(2,2),obj2(1,1);
operatorExample res=obj1+obj2;
++res;
res.display();
res++;
res.display();
++res;
res.display();
//res.operator+(res);
return 0;
}