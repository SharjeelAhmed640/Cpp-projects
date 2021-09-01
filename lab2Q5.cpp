#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

float taxJJ(float income, float HRate, int CTime)
{
   float TAX;
    if(income<=25000)
    {
        if(CTime>=30)
        {
            //cout<<HRate<<endl<<income<<endl<<CTime;
            TAX = 0.40*HRate*((CTime-30)*0.016666);
        }
    }
    else if(income>25000)
    {
        if(CTime>=20)
        TAX=0.70*HRate*((CTime-30)*0.016666);
    }
    else
    TAX=0;
    
    return TAX;
}


int main(){
 
float income,h_rate;
int c_time;
cout<<"Enter your income : ";
cin>>income;
cout<<endl<<"Enter Consulting time : ";
cin>>c_time;
cout<<endl<<"Enter hourly rate : ";
cin>>h_rate;
float tax=taxJJ(income,h_rate,c_time);
cout<<endl<<"Tax due : "<<tax<<"$";
return 0;
}