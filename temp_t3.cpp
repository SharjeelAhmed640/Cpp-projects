#include <iostream>
#include <cstring>
#include <cmath>
/*Create a class containing a function template capable of returning the sum of all the
elements in an array being passed as parameter. Show the results for two arrays, one integer
type and the other double type.*/
using namespace std;
template<class T>
class Myclass{
    T *data;
    int n;
    public:
    void setdata(T *arr,int n)
    {
        this->n=n;
         data=new T[n];
         for(int i=0;i<n;i++)
         {
             data[i]=arr[i];
         }
    }
    T sum()
    {
        T sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=data[i];
        }
        return sum;
        
    }
};
int main()
{
cout<<"Adding int array"<<endl;
Myclass<int> obj1;
int arr[]={5,2,6,78,1,4,6,76,21,1};
obj1.setdata(arr,10);
cout<<"Sum of int array : "<<obj1.sum();
cout<<"\n\nAdding float array "<<endl;
Myclass<float> obj2;
float arr2[]={1.2,25.6,56.87,1.23,24.365};
obj2.setdata(arr2,5);
cout<<"Sum of float array : "<<obj2.sum();
return 0;
}