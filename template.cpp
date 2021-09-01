#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<fstream>
template<class T>
class vector{
   public:
   int size;
   T *arr;
   vector(int m=0)
   {
      size=m;
      arr= new T[size];
   }
   T dotproduct(vector &v)
   {
      T dot=0;
      for(int i=0;i<size;i++)
      {
         dot+=this->arr[i]*v.arr[i];
      }
      return dot;
   }
};
using namespace std;

int main(){
   vector<float>  v1(3),v2(3);
   for(int i=0;i<3;i++)
   {
      v2.arr[i]=i+0.25;
      v1.arr[i]=i+0.68;
   }
   float res=v1.dotproduct(v2);
   cout<<res;
   return 0;
}