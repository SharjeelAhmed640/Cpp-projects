#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

template <class T1=int, class T2 = int >
class myclass{
    T1 data1;
    T2 data2;
    public:
        myclass(T1 a=0 , T2 b=0)
        {
            data1=a;
            data2=b;
        }
        void display()
        {
          cout<<"data1 : "<<data1<<endl<<"data2 : "<<data2<<endl;
        }
};

int main(){
   myclass<int,char> m1(5,'p');
   m1.display();
   return 0;
}