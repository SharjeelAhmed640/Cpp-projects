#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
void reg(int acc,int mins)
{
    float total=0;
    if(mins>50)
    {
        total=10; 
        mins-=50;
        total+=(0.20*mins);
    }
    else
    total=10;
    cout<<endl<<endl<<"***BILL***"<<endl
    <<"Account number : "<<acc<<endl
    <<"Service type : Regular"<<endl
    <<"Total number of mins : "<<mins+50<<endl
    <<"Total amount due : "<<total<<endl;
}

void pre(int acc,int min_d,int min_n)
{
    float total=25;
    if(min_d>75)
    {
        min_d-=75;
        total+=(0.10*min_d);
    }
    if(min_n>100)
    {
        min_n-=100;
        total+=(0.05*min_n);
    }
    cout<<endl<<endl<<"***BILL***"<<endl
    <<"Account number : "<<acc<<endl
    <<"Service type : Premium"<<endl
    <<"minutes(from 6am to 6pm) : "<<min_d+75<<endl
    <<"minutes(from 6pm to 6am) : "<<min_n<<endl
    <<"Total number of mins : "<<min_d+75+min_n<<endl
    <<"Total amount due : "<<total<<endl;
}


int main(){
 
int acc_no,no_min_d,no_min_n;
char code;
cout<<"Enter account number : ";
cin>>acc_no;
cout<<endl<<"Enter service code (r or R for regular service and p or P for premium service) : ";
cin>>code;
if(code=='p' || code=='P')
{
    cout<<endl<<"Enter number of minutes(from 6am to 6pm) : ";
    cin>>no_min_d;
    cout<<endl<<"Enter number of minutes(from 6pm to 6am) : ";
    cin>>no_min_n;
    pre(acc_no,no_min_d,no_min_n);
}
else if(code=='r' || code=='R')
{
    cout<<endl<<"Enter number of minutes(from 6am to 6pm) : ";
    cin>>no_min_d;
    cout<<endl<<"Enter number of minutes(from 6pm to 6am) : ";
    cin>>no_min_n;
    reg(acc_no,no_min_d+no_min_n);
}
else
cout<<endl<<"ERROR";
return 0;
}