#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Person{
    protected:
    int id;
    public:
    virtual void Getdata(int id,double income,string name)=0;
    virtual void DisplayData()=0;

};
class Admin:public Person{
    string name;
    double income;
    public:
    void bonus()
    {
        cout<<endl<<"Annual bonus : "<<income*0.05<<endl;
    }
    void Getdata(int id,double income,string name){
        this->id=id;
        this->income=income;
        this->name=name;
    }
    void DisplayData(){
        cout<<endl<<"Name : "<<name<<endl
        <<"ID : "<<id<<endl
        <<"Income : "<<income;
        bonus();
    }

};
class Accounts:public Person{
    string name;
    double income;
    public:
    void bonus()
    {
        cout<<endl<<"Annual bonus : "<<income*0.05<<endl;
    }
    void Getdata(int id,double income,string name){
        this->id=id;
        this->income=income;
        this->name=name;
    }
    void DisplayData(){
        cout<<endl<<"Name : "<<name<<endl
        <<"ID : "<<id<<endl
        <<"Income : "<<income;
        bonus();
    }
};

int main()
{
int id;
double income;
string name;
cout<<"Enter name : ";
getline(cin,name);
cout<<"Enter id : ";
cin>>id;
cout<<"Enter income : ";
cin>>income;
Admin ali;
ali.Getdata(id,income,name);
ali.DisplayData();
Accounts Asad;
cout<<"Enter name : ";
cin.ignore();
getline(cin,name);
cout<<"Enter id : ";
cin>>id;
cout<<"Enter income : ";
cin>>income;
Asad.Getdata(id,income,name);
Asad.DisplayData();
return 0;
}