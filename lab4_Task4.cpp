#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Book{
    int *stock,n;
    string *pub,*author,*title;
    double *price;
    public:
    Book(int n)
    {
        stock=new int[n];
        pub=new string[n];
        author = new string [n];
        title = new string [n];
        price = new double [n];
        this->n=n;
    }
    void setdata()
    {
        for(int i =0 ; i<n ; i++)
        {
            cout<<endl<<"Enter book name : ";
            cin.ignore();
            getline(cin,title[i]);
            cout<<"Enter author name : ";
            cin.ignore();
            getline(cin,author[i]);
            cout<<"Enter publisher name : ";
            cin.ignore();
            getline(cin,pub[i]);
            cout<<"Enter Copies available : ";
            cin>>stock[i];
            cout<<"Enter price : ";
            cin>>price[i];
        }
    }
    void GetBook(string title,string author)
    {
        int check=0;
        for(int i=0 ; i<n ;i++)
        {
            if(this->title[i]==title && this->author[i]==author)
            {
                cout<<endl<<"Book name : "<<this->title[i]<<endl
                <<"Author name : "<<this->author[i]<<endl
                <<"Publisher name : "<<this->pub[i]<<endl
                <<"Price : "<<this->price[i]<<endl;
                int copies;
                cout<<"how many copies do you want : ";
                cin>>copies;
                if(copies<stock[i])
                {
                    cout<<endl<<"Total price of "<<copies<<"are : "<<price[i]*copies<<"$"<<endl;
                }
                else
                {
                    cout<<endl<<copies<<"are not available at the moment "<<endl;
                }
                check=1;
                break;
            }
        }
        if(check==0)
        {
            cout<<endl<<title<<" of "<<author<<" is not available "<<endl;
        }
    }
};
int main(){
int n;
cout<<"Enter number of enteries : ";
cin>>n;
Book b1(n);
b1.setdata();
 string title,aut;
 cout<<"Enter the name of title : ";
 cin.ignore();
 getline(cin,title);
 cout<<"Enter the name of author : ";
 cin.ignore();
 getline(cin,aut);
 cout<<endl<<endl;
 b1.GetBook(title,aut);
return 0;
}