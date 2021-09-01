/*Write a program to copy the contents of one file to another*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;
int main()
{
    cout<<"Enter file name to copy(read) : ";
    string filename;
    cin>>filename;
   // cout<<filename;
    ifstream f(filename,ios::ate);
    if (! f.is_open())
  { cout << "Error opening file"; exit (1); }
    f.seekg(0);
    string copy;
    cout<<"Enter file name to write : ";
    cin>>filename;
    filename+=".txt";
    fstream temp(filename,ios::app | ios::out);
    while(getline(f,copy))
    {
        cout<<"Coping : "<<copy<<endl;
        temp<<copy<<endl;
    }
    f.close();
    temp.close();

return 0;
}