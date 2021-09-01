/*Task - 01:
Write a program that prompts the user to enter the weight of a person in kilograms and outputs the
equivalent weight in pounds. Output both the weights rounded to two decimal places. (Note that 1
kilogram = 2.2 pounds.) Format your output with two decimal places.*/

#include <iostream>    
using namespace std;
#include <iomanip>      
int main () {
  float weight;
  cout<<"Enter the weight : ";
  cin>>weight;
  cout<<"\nWeight in KG : "<<setprecision(2) << fixed << weight 
  <<"\nWeight in Pounds : "<<setprecision(2)<<fixed<<weight*2.2<<endl;
  return 0;
}
