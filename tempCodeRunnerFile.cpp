#include<iostream>
using namespace std;
int i = 0,n;
class book
{
	string title[6], author[6], publisher[6];
	float price[6];
	int stock[6];
	
	public:
		book()
		{
			title[0]="Fault in our stars";
			author[0]= "John Green";
			publisher[0]= "Dutton Books";
			price[0]=100.00;
			stock[0]=50;
			
			title[1]="Harry potter";
			author[1]= "J.K. Rowling";
			publisher[1]= "Bloomsbury publishing";
			price[1]=170.00;
			stock[1]=100;
			
			title[2]="Me before you";
			author[2]= "Jojo Moyees";
			publisher[2]= "Penguin books";
			price[2]=120.00;
			stock[2]=70;
			
			title[3]="After";
			author[3]= "Anna Todd";
			publisher[3]= "Wattpad publication";
			price[3]=150.00;
			stock[3]=75;
			
			title[4]="Maybe someday";
			author[4]= "Colleen Hoover";
			publisher[4]= "Simon & Schuster";
			price[4]=200.00;
			stock[4]=80;
			
			title[5]="Alchemist";
			author[5]= "Paulo Coelho";
			publisher[5]= "Harper Collins";
			price[5]=150.00;
			stock[5]=100;
			
		}
		
		void getbook(string name, string auth)
		{
            int check=0;
			for(i=0; i<6; i++)
			{
				if(title[i]==name && author[i]==auth)
				{
					cout<<endl<<"Book name : "<<title[i]<<endl
					<<"Author name : "<<author[i]<<endl
					<<"Publisher name : "<<publisher[i]<<endl
					<<"Price : Rs."<<price[i]<<endl;
					cout<<"How many copies you want? : ";
	                cin>>n;
	                if(stock[i]>=n)
	                {
	                	cout<<"\nTotal amount: Rs."<<price[i]*n<<endl;
					}
					else
					{
						cout<<"Required copies not in stock";
					}
                    check=1;
                    break;
				}
				
			}
            if(check==0)
            {
                cout<<"Sorry your desired book is unavailable";
            }
		}
};
int main()
{
	int n;
	string t, a;
	cout<<"Enter title of book: ";
	getline(cin, t);
	cout<<"Enter author's name: ";
	getline(cin, a);
	book b;
	b.getbook(t,a);
	
}