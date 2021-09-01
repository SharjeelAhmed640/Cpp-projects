#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int main()
{
string name;
float marks[5];
float total=0;
cout<<"Enter name : ";
getline(cin,name);
for(int i=0;i<5;i++)
{
    cout<<"Enter marks of subj("<<i+1<<") : ";
    cin>>marks[i];
    total+=marks[i];
}
float perc=total/5;
cout<<"Name : "<<name<<endl
<<"Percentage : "<<perc<<endl;
if(perc<50)
cout<<"REMARKS : Fail"<<endl;
else if(perc<60 && perc>=50)
cout<<"REMARKS : C"<<endl;
else if(perc<70 && perc>=60)
cout<<"REMARKS : B"<<endl;
else if(perc<80 && perc>=70)
cout<<"REMARKS : A"<<endl;
else
cout<<"REMARKS : A+"<<endl;
return 0;
}