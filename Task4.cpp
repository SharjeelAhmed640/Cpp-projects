#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class MemberType{
    string name;
    int id,book_bought;
    double amount;
    public:
    MemberType()
    {}
    void setData(int id,int books,double amount,string name)
    {
        this->amount=amount;
        this->name=name;
        book_bought=books;
        this->id=id;
    }
    void printData()
    {
        cout<<endl<<"Name : "<<name
        <<endl<<"ID : "<<id<<endl
        <<"Books bought # "<<book_bought
        <<endl<<"Money spent : "<<amount<<"$"<<endl;
    }
};

int main()
{
MemberType mem1;
int id,book;
string name;
double amount;
cout<<"Enter name : ";
getline(cin,name);
cout<<"Enter ID : ";
cin>>id;
cout<<"Enter number of books bouught : ";
cin>>book;
cout<<"Amount spent : ";
cin>>amount;
mem1.setData(id,book,amount,name);
mem1.printData();
return 0;
}