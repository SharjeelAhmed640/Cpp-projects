#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int main()
{
string name,cnic,uni,pname;
double cgpa;
cout<<"Enter your name : ";
getline(cin,name);

cout<<"Enter your father name : ";
getline(cin,pname);

cout<<"Enter your cnic : ";
cin>>cnic;

cout<<"Enter uni name : ";
cin.ignore();
getline(cin,uni);

cout<<"Enter cgpa : ";
cin>>cgpa;


cout<<endl<<endl<<"Name : "<<name<<endl
<<"Father name : "<<pname<<endl
<<"CNIC : "<<cnic<<endl
<<"University name : "<<uni<<endl
<<"CGPA : "<<cgpa<<endl;
return 0;
}