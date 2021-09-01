#include<iostream>
#include<string>
using namespace std;
class employee{
    public:
    int id;
    float salary;
    employee(int A=0,float B=0)
    {
        id=A;
        salary=B;
    }
     void display()
     {
         cout<<"id is : "<<id<<"salary is : "<<salary<<endl;
     }
};
class programmer : public employee{
    public:
    int lancode;
    programmer(int x=0 ,  int y=0 , float z=0)
    {
        id=x;
        lancode=y;
        salary=z;
    }
    void display()
     {
         cout<<"id is : "<<id<<"\tsalary is : "<<salary<<"\tlanguage code is : "<<lancode<<endl;
     }
};
int main(){
   employee sharjeel;
   programmer ahmed(3,10,66);
   ahmed.display();
   return 0;
}