#include <iostream>
#include <cstring>
#include <cmath>
#include<fstream>
using namespace std;
int main()
{
    string s;
    double d;
    int i;
fstream file;
file.open("test.txt",ios::out);
file<<"hi"<<endl<<3.3<<endl<<2<<endl;
file.close();
file.open("test.txt",ios::in);
file.seekg(0);
   getline(file,s);
   file>>d>>i;
   cout<<s<<endl<<d<<endl<<i;
return 0;
}