#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int main()
{
int n;
cout<<"Enter rhe number you want table of : ";
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<n<<" X "<<1+i<<" = "<<n*(1+i)<<endl;
}
return 0;
}