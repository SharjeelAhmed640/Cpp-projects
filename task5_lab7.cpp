#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class student{
    protected:
    string name;
    int id;
    public:
    void  setdata(string const name,int const id)
    {
        this->name=name;
        this->id=id;
    }
    void const  display()
    {
        cout<<"Name : "<<name<<endl
        <<"ID : "<<id<<endl;
    }
};

class academic:public student{
    float cgpa;
    public:
    void virtual setdata(float const g)
    {
        cgpa=g;
    }
    void  const display()
    {
        cout<<"CGPA : "<<cgpa<<endl;
    }
};
int main()
{
int id;
string name;
float cgpa;
cout<<"Enter name : "; cin>>name;
cout<<"Enter ID : "; cin>>id;
cout<<"Enter CGPA : "; cin>>cgpa;
student *ptr;
academic mr;
ptr=&mr;
ptr->setdata(name,id);
ptr->display();
mr.setdata(cgpa);
mr.display();
return 0;
}