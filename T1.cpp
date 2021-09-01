#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


//Q1
// char to store any character whther numeric or alphanumeric but only once charachter in variable of char (1 byte)
// int for storing integer data e.g whole numbers (2 bytes)
// float for storing fractional data e.g (4.5 , 0.99 etc) (4 bytes)(7 decimal digits precision)
// double for storing large data wheter whole or decimal (8 bytes)(15 decimal digits precision)

//Q7 e.g
#define mynum 99;

int main()
{

//Q2
int num=10;
float fnum=10.99;
char c='A';
double dnum=2141;

//Q3 using previously decleared members
cout<<"int : "<<num<<endl
<<"float : "<<fnum<<endl
<<"Doule : "<<dnum<<endl
<<"Char : "<<c<<endl;

//Q4
string st="Humdard university in pursuit of excellence";
cout<<st;

//Q5
//representing special charachters suc as space or backspace or new line by ascii
char spchar=10;
cout <<spchar;

//Q6
const int number=10;
char arr[number];

//Q7
//by keyword define you can define any global variable whic has scope throughout the program
//example above main

//Q8
//increment (post)i++ or ++i(pre)
//decrement (post)i-- or --i(pre)
//comparision are same as relational
//bitwise & , | , ^ , !
//assignment int a=5 in this = is assigment operator
//airthmatic a+b , a-b , a/b ,a*b  (-,+,/,*) are airthmatic operator
//compound *=, /= ,%=. &=,|=, ^=, +=, -=, <<= ,>>=
//relational ==, !=, < , > , <= , >=

//Q9
int num1,num2;
cout<<"enter num1 : ";
cin>>num1;

cout<<"Enter num2 : ";
cin>>num2;

num1>num2 ? cout<<"num1 is greater"<<endl : cout<<"num2 is greater"<<endl;

//Q10
string mys;
cout<<"Enter string : ";
cin>>mys;
cout<<mys;



//Q11
//by using getline we can the intput did not terminate after space which occur in cin
cout<<"Enter string with spcae : ";
getline(cin,mys);
cout<<mys;

//Q12
int num12;
printf("Enter number : ");
scanf("%d",&num12);
printf("%d", num12);

//Q13
float n1,n2;
cout<<"Enter number 1 : ";
cin>>n1;
cout<<"Enter number 2 : ";
cin>>n2;
//if else
if(n1>n2)
cout<<n1<<" is greater than "<<n2<<endl;
else
cout<<n2<<" is greater than "<<n1<<endl;

//while 
int i=0;
while(i<5)
{
    cout<<"value of i is : "<<i++<<endl;
}
do{
    i=10;
    cout<<"in do while value of i is "<<i++<<endl;//if cond is false it will execute at least one time
}while(i<6);

//Q14
//break continue
for(i=0;i<20;i++)
{
    if(i%2==0)
    {
        continue;//when ever this is true all the line below it, will not execute ant loop perform its next iteration
    }
    cout<<"Only printing odd numbers : "<<i<<endl;
    if(i==15)//when ever this is true it will break the loop
    break;
}
return 0;
}