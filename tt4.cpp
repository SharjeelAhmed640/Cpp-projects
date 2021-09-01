#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
//add function 
int main()
{
float n1,n2,n3;
cout<<"Enter marks of subject 1 : ";
cin>>n1;
cout<<"Enter marks of subject 2 : ";
cin>>n2;
cout<<"Enter marks of subject 3 : ";
cin>>n3;

cout<<"Subject 1 marks : "<<n1<<endl
<<"Subject 2 marks : "<<n2<<endl
<<"Subject 3 marks : "<<n3<<endl
<<"Percentage : "<<(n1+n2+n3)/3<<"%"<<endl;
return 0;
}