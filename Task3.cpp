#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
struct BOOK
{
    int ISBN, stock;
    string name, author, pub;
};
class BookType
{
    BOOK DATA;

public:
    void setdata(int isbn, string NAME, string AUTHOR, string PUB, int stock)
    {
        DATA.ISBN = isbn;
        DATA.name = NAME;
        DATA.author = AUTHOR;
        DATA.pub = PUB;
        DATA.stock = stock;
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
};

int main()
{
    int i, isbn, stock, N;
    cout << "Enter no of records you want to enter : ";
    cin >> N;
    BOOK data;
    string n, a, p;
    BookType B[N];
    //B[0].setdata()
    for (i = 0; i < N; i++)
    {
        cout << "Enter Book name : ";
        cin >> n;
        cout << "Enter author name : ";
        fflush(stdin);
        cin >> a;
        cout << "Enter publisher name : ";
        fflush(stdin);
        cin >> p;
        cout << "Enter ISBN : ";
        cin >> isbn;
        cout << "Enter number of copies : ";
        cin >> stock;
        B[i].setdata(isbn, n, a, p, stock);
        cout << endl;
    }
    for (i = 0; i < N; i++)
    {
        data = B[i].GetBookInfo();

        cout << endl
             << "Book name : " << data.name << endl
             << "ISBN number : " << data.ISBN << endl
             << "Author name : " << data.author << endl
             << "Publisher name : " << data.pub << endl
             << "Number of copies available : " << data.stock << endl;
    }
    int choose=1;
    

int check = 0;
while (choose<=9 && choose>0)
{cout << endl
         << "1 for update isbn\n2 for print isbn\n3 for update author\n4 for print author\n5 for update publisher\n6 for print publisher\n7 for update stock\n8 for print stock\n9 for exit " << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "Enter isbn to update ISBN : ";
        cin >> isbn;
         check = 0;
        for (i = 0; i < N; i++)
        {
            if (isbn == B[i].GetISBN())
            {
                check = 1;
                cout << "Enter new ISBN : ";
                cin >> isbn;
                B[i].SetISBN(isbn);
                break;
            }
            if (check == 0)
            {
                cout << endl
                     << "Enter valid ISBN" << endl;
                
            }
        }
        break;
   case 2:
        for (i = 0; i < N; i++)
        {
            data = B[i].GetBookInfo();

            cout << endl
                 << "Book name : " << data.name << endl
                 << "ISBN number : " << data.ISBN << endl;
        }
        system("pause");
        break;
    case 3:
        cout << "Enter isbn to update Author : ";
        cin >> isbn;
         check = 0;
        for (i = 0; i < N; i++)
        {
            if (isbn == B[i].GetISBN())
            {
                check = 1;
                cout << "Enter new author name : ";
                cin >> a;
                B[i].SetAut(a);
                break;
            }
            if (check == 0)
            {
                cout << endl
                     << "Enter valid ISBN" << endl;
                
            }
        }
        break;

    case 4:
        for (i = 0; i < N; i++)
        {
            data = B[i].GetBookInfo();

            cout << endl
                 << "Book name : " << data.name << endl
                 << "Author name : " << data.author << endl;
        }

        system("pause");
        break;
    case 5:
        cout << "Enter isbn to update Publisher : ";
        cin >> isbn;
         check = 0;
        for (i = 0; i < N; i++)
        {
            if (isbn == B[i].GetISBN())
            {
                check = 1;
                cout << "Enter new Publisher name : ";
                cin >> a;
                B[i].SetPub(a);
                break;
            }
            if (check == 0)
            {
                cout << endl
                     << "Enter valid ISBN" << endl;
               
            }
        }

        break;
    case 6:
    for(i=0;i<N;i++)
	{
		data=B[i].GetBookInfo();

        cout<<endl<<"Book name : "<<data.name<<endl
			<<"Publisher  name : "<<data.pub<<endl;
	}
    system("pause");
    break;
    case 7:
    cout << "Enter isbn to update stock : ";
        cin >> isbn;
         check = 0;
        for (i = 0; i < N; i++)
        {
            if (isbn == B[i].GetISBN())
            {
                check = 1;
                cout << "Enter new stock : ";
                cin >> stock;
                B[i].setStock(stock);
                break;
            }
            if (check == 0)
            {
                cout << endl
                     << "Enter valid ISBN" << endl;
                
            }
        }
        break;
        case 8:
        for(i=0;i<N;i++)
	{
		data=B[i].GetBookInfo();

        cout<<endl<<"Book name : "<<data.name<<endl
			<<"Stock : "<<data.stock<<endl;
	}
   system("pause");
    break;
    case 9:
    break;
    default:
    cout<<endl<<"Wrong input"<<endl;
    
    break;
    }
}
}