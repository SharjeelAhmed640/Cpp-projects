#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int main()
{
float cgpa;
cout<<"Enter CGPA : ";
cin>>cgpa;
if(cgpa<=4 && cgpa>=3.7)
cout<<"Excelent";

else if(cgpa<=3.7 && cgpa>=3.4)
cout<<"Very good";

else if(cgpa<=3.4 && cgpa>=3)
cout<<"Good";

else if(cgpa<=3 && cgpa>=2)
cout<<"Fair";

else if(cgpa<=2 && cgpa>=1)
cout<<"Need improvement";

else if(cgpa<=1&& cgpa>=0)
cout<<"Poor";


}