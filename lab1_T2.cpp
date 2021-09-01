/*Task - 02:
A movie in a local theater is in great demand. To help a local charity, the theater owner has decided
to donate to the charity a portion of the gross amount generated from the movie. This example
designs and implements a program that prompts the user to input the movie name, adult ticket
price, child ticket price, number of adult tickets sold, number of child tickets sold, and
percentage of the gross amount to be donated to the charity. The output of the program is as
follows.*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
main()
{
	string name;
	float a_tik,c_tik,gross,donated,net_sale,percent;
    int no_a_tik,no_c_tik,sold;
	cout<<"Enter the name of the movie : ";
	getline(cin,name);
	
	cout<<"Enter Adult ticket price : ";
	cin>>a_tik;
	
	cout<<"Enter Child ticket price : ";
	cin>>c_tik;
	
	cout<<"Enter Number of Adult Ticket Sold : ";
	cin>>no_a_tik;
	
	cout<<"Enter Number of Child Tickets Sold : ";
	cin>>no_c_tik;
	
	cout<<"Enter the percentage of the gross amount to be Donated : ";
	cin>>percent;
	
	int total_tickets=no_a_tik+no_c_tik;
    float gross_amount=(float)(a_tik*no_a_tik)+(c_tik*no_c_tik),amount_donated=(float)((0.01*percent)*(a_tik*no_a_tik)+(c_tik*no_c_tik));
	cout<<endl<<"***********************************************"<<endl;
	
	cout<< setw(50)<<left<<"Movie Name : "<<name<<endl;
	cout<<setw(50)<<left<<"Number of Tickets Sold : "<<total_tickets<<endl;
	cout<<setw(50)<<left<<"Gross Amount : "<< gross_amount <<endl;
	cout<<setw(50)<<left<<"Percentage of Gross Amount Donated : "<<percent<<endl;
	cout<<setw(50)<<left<<"Amount Donated : "<< amount_donated <<endl;
	cout<<setw(50)<<left<<"Net Sale : "<<gross_amount-amount_donated<<endl;
    cout<<endl<<"***********************************************"<<endl;
}