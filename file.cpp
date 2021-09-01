#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Student{
private:
    char name[40];
    char grade;
    float marks;
public:
    void getdata();
    void display();
};

void Student::getdata(){
    char ch;
    cin.get(ch);
    cout<<"Enter name : ";
    cin.getline(name,40);
    cout<<"Enter grade : ";
    cin>>grade;
    cout<<"Enter marks : ";
    cin>>marks;
    cout<<"\n";
}

void Student::display(){
    cout<<"Name : "<<name<<"\t";
    cout<<"Grade : "<<grade<<"\t";
    cout<<"Marks : "<<marks<<"\t"<<"\n";
}

int main(){
    system("cls");
    Student arts;
    fstream f;
    f.open("stu.txt",ios::out | ios::app | ios::ate);
    if(!f){
        cerr<<"Cannot open file !";
        return 1;
    }
    for(int i=0;i<1;i++){
        arts.getdata();
        f.write((char*)&arts,sizeof(arts));
    }
   // f.seekg(0); //The question is about this statement;
   f.close();
   f.open("stu.txt",ios::in);
    cout<<"The contents of stu.txt are shown below : \n";
    while(!f.eof()){
        f.read((char*)&arts,sizeof(arts));
        arts.display();
    }
    f.close();
    return 0;
}