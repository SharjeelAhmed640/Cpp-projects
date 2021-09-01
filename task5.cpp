#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
 // namespace std;

struct BOOK
{
    int ISBN, stock;
    string name, author, pub;
    double price;
};
class BookType
{
    BOOK DATA;
    int n=0;

public:
    void setdata(int isbn, string NAME, string AUTHOR, string PUB, int stock,double price,int n)
    {
        this->DATA.price=price;
        DATA.ISBN = isbn;
        DATA.name = NAME;
        DATA.author = AUTHOR;
        DATA.pub = PUB;
        DATA.stock = stock;
        this->n=n;
    }
    BOOK GetBookInfo()
    {
        return DATA;
    }
    int GetStock()
    {
        return DATA.stock;
    }
    void setStock(int n)
    {
        DATA.stock = n;
    }
    void SetISBN(int n)
    {
        DATA.ISBN = n;
    }
    int GetISBN()
    {
        return DATA.ISBN;
    }
    void SetPub(string n)
    {
        DATA.pub = n;
    }
    string GetPub()
    {
        return DATA.pub;
    }
    void SetAut(string n)
    {
        DATA.author = n;
    }
    string GetAut()
    {
        return DATA.author;
    }
    string getname()
    {
        return DATA.name;
    }
    int getn()
    {
        return n;
    }
    double buy(double price)
    {
        static double pri=0.0;
        static int n=0;
        if(n==10)
        {n=0;
        return pri/10;
        }
        else
        {
            n++;
            pri+=price;
            return 0.0;
        }
    }
};

using namespace std;
int main()
{
int pin;
int choose;
cout<<"press 2 to search book by name and author name\npress 3 to buy book"<<endl;
cin>>choose;
BOOK bookinfo;



        cout<<endl<<"How many records you want to enter : ";
        int N;
cin>>N;
BookType Data[N];
        
        for(int i=0; i<N;i++)
        {
        cout << "Enter Book name : ";
        cin >> bookinfo.name;
        cout << "Enter author name : ";
        fflush(stdin);
        cin >> bookinfo.author;
        cout << "Enter publisher name : ";
        fflush(stdin);
        cin >> bookinfo.pub;
        cout << "Enter ISBN : ";
        cin >> bookinfo.ISBN;
        cout << "Enter number of copies : ";
        cin >> bookinfo.stock;
        Data[i].setdata(bookinfo.ISBN, bookinfo.name, bookinfo.author, bookinfo.pub, bookinfo.stock,bookinfo.price, N);
        cout << endl;
        }
switch (choose)
{
case 1:

case 2:
cout<<"Enter book name : ";
cin.ignore();
getline(cin,bookinfo.name);
cout<<"Enter book Author name : ";
cin.ignore();
getline(cin,bookinfo.author);
for(int i=0;i<(Data[0].getn());i++)
{
    if(bookinfo.name==Data[i].getname() && bookinfo.author==Data[i].GetAut())
    {
        bookinfo=Data[i].GetBookInfo();
        cout << endl
             << "Book name : " << bookinfo.name << endl
             << "ISBN number : " << bookinfo.ISBN << endl
             << "Author name : " << bookinfo.author << endl
             << "Publisher name : " << bookinfo.pub << endl
             << "Number of copies available : " << bookinfo.stock << endl
             <<"Price : "<<bookinfo.price<<"$ only "<<endl;
             break;
    }
}

break;
case 3:
cout<<endl<<"Enter isbn number : ";
cin>>bookinfo.ISBN;
for(int i=0;i<(Data[0].getn());i++)
{
    if(bookinfo.ISBN==Data[i].GetISBN())
    {
         bookinfo=Data[i].GetBookInfo();
        cout << endl
             << "Book name : " << bookinfo.name << endl
             << "ISBN number : " << bookinfo.ISBN << endl
             << "Author name : " << bookinfo.author << endl
             << "Publisher name : " << bookinfo.pub << endl
             << "Number of copies available : " << bookinfo.stock << endl
             <<"Price : "<<bookinfo.price<<"$ only "<<endl;
             double dis = Data[i].buy(bookinfo.price);
             if(dis==0)
             cout<<"Price after discount : "<<bookinfo.price-((bookinfo.price/100)*5)<<"$ only"<<endl;
             else
             cout<<"For your 11th book get discout of : "<<bookinfo.price-((bookinfo.price/100)*5)-dis<<"$ only"<<endl;
             break;
    }
    else
    {
        cout<<"Error";
    }
}
break;
default:
cout<<endl<<"invalid input"<<endl;
    break;
}
return 0;
}