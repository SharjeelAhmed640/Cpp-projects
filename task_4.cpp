#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
// Design and implement a program that shows the relationship between person, student and
// professor. Your person class must contain two pure virtual functions named getData() of type void
// and isOutstanding() of type bool and as well getName() and putName() that will read and print the
// person name. Class student must consist of function name getData (), which reads the GPA of
// specific person and isOutstanding() function which returns true if the person GPA is greater than
// 3.5 else should return false. Class professor should take the respective persons publications in
// getData() and will return true in Outstanding() if publications are greater than 100 else will return
// false . Your main function should ask the user either you want to insert the data in professor or
// student until and unless user so no to add more data.
class person{
    protected:
    string name;
    public:
    void virtual  getdata(float)=0;
    bool virtual  isOutstanding()=0;
    void putname(const string n)
    {
        name=n;
    }
    string const getname ()
    {
        return name;
    }
};
class student:public person{
    protected:
    float gpa;
    public:
    void   getdata(float g)
    {
        gpa=g;
    }
    bool   isOutstanding()
    {
        if(gpa>=3.5)
        return true;
        else return false;
    }
};
class professor:public person{
    protected:
    float pub;
    public:
    void   getdata(float g)
    {
        pub=g;
    }
    bool   isOutstanding()
    {
        if(pub>=100)
        return true;
        else return false;
    }
};
int main()
{
string name;
float gpa_or_pub;
cout<<"Enter name(professor) : ";
getline(cin,name);
cout<<"Enter publication : ";
cin>>gpa_or_pub;
professor p1;
p1.putname(name);
p1.getdata(gpa_or_pub);
if(p1.isOutstanding())
{
    cout<<"Outstanding=true"<<endl;
}
else cout<<"Outstanding=false"<<endl;
cout<<"Enter name(student) : ";
cin.ignore();
getline(cin,name);
cout<<"Enter GPA : ";
cin>>gpa_or_pub;
student s1;
s1.putname(name);
s1.getdata(gpa_or_pub);
if(s1.isOutstanding())
{
    cout<<"Outstanding=true"<<endl;
}
else cout<<"Outstanding=false"<<endl;

return 0;
}