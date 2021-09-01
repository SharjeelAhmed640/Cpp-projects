#include <iostream>
#include <cstring>
#include <cmath>
#include<fstream>

using namespace std;

/*Write a function in C++ to print the count of word the as an independent word in a text file
STORY.TXT.for example, if the content of the file STORY.TXT is
There was a monkey in the zoo. The monkey was very naughty.
Then the output of the program should be 2*/
int main()
{
string file;
cout<<"Enter file : ";
cin>>file;
file+=".txt";
ifstream f1,f2;
f1.open(file,ios::ate);
 if (! f1.is_open())
  { cout << "Error opening file"; exit (1); }
f2.open(file,ios::ate);
 if (! f2.is_open())
  { cout << "Error opening file"; exit (1); }
f1.seekg(0);
f2.seekg(0);
string word1,word2;
bool check=false;
int count=0;
int g;
while(!f1.eof())
{f1>>word1;
g=f1.tellg();
f2.seekg(g);
f2>>word2;
//cout<<"in puter";
    while(f2>>word2)
    {cout<<word1<<"\t"<<word2<<"\t"<<check<<endl;
        //cout<<word1<<"\t"<<word2<<endl;
        if(word1==word2)
        {
            count++;
           // cout<<"in fifiifif";
        }
    }
    f2.close();
    f2.open(file,ios::ate);
 if (! f2.is_open())
  { cout << "Error opening file"; exit (1); }

    check=false;
}
f1.close();
f2.close();
cout<<"Count : "<<count;
return 0;
}