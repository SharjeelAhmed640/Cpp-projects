#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/*Write a program to calculate bonus of the employees. The class master derives the information
from both admin and account classes which intern derives information from class person. Create
base and all derived classes having same member functions called getdata, display data and bonus.
Create a base class pointer that capable of accessing data of any class and calculates bonus of the
specified employee. (Hint: Use virtual functions)*/
class person
{
protected:
    string name;
    int age;
    float bouns;

public:
    void virtual getdata(string n, int a)
    {
        name = n;
        age = a;
    }
    void virtual getdata(int n, double a){}
    void virtual display()
    {
        cout << endl
             << "Name : " << name
             << endl
             << "Age : " << age << endl;
    }
    void virtual bonus(float bon){
        bouns=bon;
        cout<<"person bonus : "<<bouns <<endl;
    }
    virtual ~person(){}
};
class admin:public virtual person{
    protected:
    int id;
    double salary;
    public:
    
    void virtual getdata(int  i, double  s)
    {
        id=i;
        salary=s;
    }
    void virtual display()
    {
       cout << endl
             << "id : " << id
             << endl
             << "salary : " << salary << endl;
    }
    void virtual bonus( float bon){
        bouns=bon;
        cout<<"admin bonus : "<<bouns<<endl;
    }
};
class accounts:virtual public person{
    protected:
    double salary;
    int id;
    public:
 void virtual getdata(int  i, double  s)
    {
        id=i;
        salary=s;
    }
    void virtual display()
    {
        cout << endl
             << "id : " << id
             << endl
             << "salary : " << salary << endl;
    }
    void virtual bonus(float bon){
        bouns=bon;
        cout<<"accounts bonus : "<<bouns<<endl;
    }
};
class master:public admin,public accounts{
    int id;
    double salary;
    public:
    void getdata(int  i, double  s)
    {
        id=i;
        salary=s;
    }
    void display()
    {
        cout << endl
             << "id : " << id
             << endl
             << "salary : " << salary << endl;
    }
    void bonus(float bon){
        bouns=bon;
        cout<<"master bonus : "<<bouns<<endl;
    }
};
int main()
{
    person p;
    accounts a;
    admin ad;
    master m;


    person *baseptr;
    baseptr=&p;
    baseptr->getdata("sharjeel",19);
    baseptr->display();
    baseptr->bonus(500);

    baseptr=&m;
    baseptr->getdata(59,8500);
    baseptr->display();
    baseptr->bonus(18);
    return 0;
}