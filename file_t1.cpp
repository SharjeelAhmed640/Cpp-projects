/*Write a program to implement I/O operations on characters. I/O operations includes inputting a
string, calculating length of the string, Storing the String in a file and fetch the stored characters
from it.*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;



int main()
{
fstream out;
out.open("TASK1.txt",ios::out | ios::app);

string s;
cout<<"Enter a string : ";
getline(cin,s);
s=s+"\n";
out<<s;
out.close();
ifstream in("TASK1.txt",ios::ate);
in.seekg(0);
cout<<"Reading from file"<<endl;
while(getline(in,s))
{
    cout<<s<<endl;
    cout<<s.length();
}


}