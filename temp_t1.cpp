#include <iostream>
#include <cstring>
#include <cmath>
/*Implement bubble sort algorithm using function template and show the results for the
following arrays
 7, 5, 4, 3, 9, 8, 6
 4.3, 2.5, -0.9, 100.2, 3.0*/
using namespace std;

template<class T>
void bubblesort(T *arr,T n)
{
    T temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
template<class T>
void print(T *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<endl;
}
int main()
{
int arr[]={7, 5, 4, 3, 9, 8, 6};
bubblesort(arr,7);
print(arr,7);
float array[]={ 4.3, 2.5, -0.9, 100.2, 3.0};
bubblesort(array,(float)5);
print(array,5);
return 0;
}