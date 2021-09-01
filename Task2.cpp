#include <iostream>
#include <cstring>
using namespace std;

class PersonType{
	private:
	string FName ;
    string  LName , MName ;
	public:
		void SetFName(string name){
			FName=name;
		}
		void SetLName(string name){
			LName=name;
            cout<<LName;
		}
		void SetMName(string name){
			MName=name;
		}
		void CheckFName(string name)
		{
			if(name == FName)
			cout<<endl<<"First name is same "<<endl;
			else
			cout<<endl<<"First name is not same "<<endl;
		}
		void CheckLName(string name1){
			if(name1 == LName)
			{
				cout<<endl<<"Last name is same "<<endl;	
			}
			
			else
			cout<<endl<<"Last name is not same "<<endl;
		}
		
};
int main()
{
	PersonType per1;
	string fname,lname,mname;
	cout<<"Enter first name : ";
	cin>>fname;
	per1.SetFName(fname);
	cout<<"Enter middle name : ";
	cin>>mname;
	per1.SetMName(mname);
	cout<<"Enter last name : ";
	cin>>mname;
	per1.SetLName(lname);
	
	//system("CLS");
	string namef,namel;
	cout<<endl<<"Enter first name : ";
	cin>>namef;
	per1.CheckFName(namef);
	cout<<endl<<"Enter last name : ";
	cin>>namel;
	per1.CheckLName(namel);
		
	return 0;
}