/*Task - 05:
Write a program that declares a struct to store the data of a baseball player (player’s name, number
of home runs, and number of hits). Declare an array of 10 components to store the data of 10
baseball players. Your program must be able to search the array to find the index of a specific
player, and update the data of a player. Your program should be menu driven, giving the user
various choices.*/

#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
struct info
{
    string name;
    int no_homerun,no_hits;
};

int main(){
 
info rec[10];
int count=3;
for (int i = 0; i < count; i++)
{
    cout<<"Enter player name : ";
    cin>>rec[i].name;
    cout<<"Enter number of home runs : ";
    cin>>rec[i].no_homerun;
    cout<<"Enter number of hits : ";
    cin>>rec[i].no_hits;
}
string input;
int select;

cout
<<"press 1 to search specific player name "<<endl
<<"Press 2 to view all "<<endl
<<"press 3 to veiw players who hit more than 5 homeruns "<<endl;
cin>>select;
switch (select)
{
case 1:
cout<<"\n\nEnter player name you want to search : ";
cin>>input;
    for (int  i = 0; i < count; i++)
{
    if(input==rec[i].name)
    {
        cout
        <<endl<<"Name           : "<<rec[i].name<<endl
        <<"No of homeruns : "<<rec[i].no_homerun<<endl
        <<"No of hits     : "<<rec[i].no_hits<<endl<<endl;
    }
}
    break;
case 2:
for (int  i = 0; i < count; i++)
{
    
    
        cout
        <<endl<<"Name           : "<<rec[i].name<<endl
        <<"No of homeruns : "<<rec[i].no_homerun<<endl
        <<"No of hits     : "<<rec[i].no_hits<<endl<<endl;
    
}
break;
case 3:
for (int  i = 0; i < count; i++)
{
    if(rec[i].no_homerun>=5)
    {
        cout
        <<endl<<"Name           : "<<rec[i].name<<endl
        <<"No of homeruns : "<<rec[i].no_homerun<<endl
        <<"No of hits     : "<<rec[i].no_hits<<endl<<endl;
    }
}
default:
    break;
}
return 0;
}