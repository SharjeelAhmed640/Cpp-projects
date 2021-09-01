#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class PROTECTED{
    protected:
    int age;
    string s1;
    public:
    PROTECTED(string NAME,int AGE=0){
        s1=NAME;
        age=AGE;
    }
    void dislay()
    {
        cout<<"NAME : "<<s1<<"\tAGE  : "<<age<<endl;
    }
};

int main(){
    string name;
    cout<<"ENTER YOUR NAME : ";
    getline(cin,name);
    int age;
cout<<"ENTER YOUR AGE : ";
cin>>age;
   PROTECTED A(name,age);
   A.dislay();
   return 0;
}