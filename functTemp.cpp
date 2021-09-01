#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
template<class T>
void swapp(T *a,T *b)
{
    T temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
   char a='a',b='b';
    swapp(&a,&b);
    cout<<a<<endl<<b;
   return 0;
}