#include <iostream>
#include <cstring>
#include <cmath>
#include<string.h>
#include<fstream>

using namespace std;
class person{
    int age;
    char name[30];
    public:
    person(int a ,char n[30])
    {
        strcpy(name,n);
        age=a;
    }
    person(){}
    void write()
    {
        ofstream out;
        out.open("data.txt",ios::app);
        person p;
        p.age=this->age;
        strcpy(p.name,this->name);
        out.write((char *)&p,sizeof(p));
        out.close();
    }
    void read()
    {
        ifstream in;
        in.open("data.txt",ios::ate);
        in.seekg(0);
        person p;
        in.read((char *)&p,sizeof(p));
        while( !in.eof() )
        {
            cout<<"Name : "<<p.name<<endl
            <<"AGE : "<<p.age<<endl;
            in.read((char *)&p,sizeof(p));
        }
    }
};


int main()
{
cout<<"Enter name : ";

char name[20];
cin>>name;

int age;
cout<<"Enter age : ";
cin>>age;
person p(age,name);
p.write();
p.read();
return 0;
}