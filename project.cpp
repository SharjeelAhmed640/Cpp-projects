#include <iostream>
#include <cstring>
#include <cmath>
#include<fstream>

using namespace std;
class Book{
    string name;
    int id;
    double price;
    public:
    Book()
    {
        name="no name";
        id=0;
        price=0.0;
    }
    void setdata()
    {
        cout<<"Enter book name : ";
        getline(cin,name);
        cout<<"Enter price : ";
        cin>>price;
        cout<<"Enter id : ";
        cin>>id;
        cin.ignore();
    }
    void showdata()
    {
        cout<<"Name : "<<name<<endl
        <<"ID : "<<id<<endl
        <<"Proce :"<<price<<endl;
    }
    void add()
    {
        ofstream file;
        file.open("Text.txt",ios::app);
        file.write((char*)this,sizeof(*this));
        file.close();
    }
    void read()
    {
        Book b;
        fstream file;
        file.open("Text.txt",ios::ate | ios::in | ios::out);
        file.seekg(0);
        file.read((char*)&b,sizeof(b));
        while(!file.eof())
        {
            b.showdata();
            file.read((char*)&b,sizeof(b));
        }
    }
    
};
int main()
{
Book b1,b2;
b1.setdata();

cout<<endl<<endl<<endl;
b1.read();
return 0;
}