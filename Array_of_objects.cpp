#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class base{
    protected:
    int x;
    public:
    base(){}
    base(int x)
    {
        this->x=x;
    }
};
class derived:base{
    int y;
    public:
    derived(){}
    derived(int x,int y):base(x){
        this->y=y;
    }
    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
};

int main()
{
derived *arr=new derived[10];
for(int i=0;i<10;i++)
{
    arr[i]=derived(i,i+1);
}
for(int i=0;i<10;i++)
arr[i].display();


// 2d array
int **x=new int*[4];
for (int i=0;i<4;i++)
{
    x[i]=new int [4];
}
for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    x[i][j]=i+j;
}
for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    cout<<x[i][j]<<" ";
    cout<<endl;
}
cout<<endl<<endl;
int loop=0;
int *ptr=new int[3*4];
for(int i=0;i<3;i++)
for(int j=0;j<4;j++)
*(ptr+i*3+j)=loop++;
for(int i=0;i<3;i++)
{
    for(int j=0;j<4;j++)
    cout<<*(ptr+i*3+j)<<" ";
    cout<<endl;
}

return 0;
}