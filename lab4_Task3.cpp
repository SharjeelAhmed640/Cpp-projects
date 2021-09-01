#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Invoice{
    string partNO, des;
    int quantity;
    double price;
    public:
    Invoice(string PartNO,string des,int quantity,double price)
    {
        this->partNO=partNO;
        this->des=des;
        if(quantity<0)
        this->quantity=0;
        else
        this->quantity=quantity;
        if(price<0.0)
        this->price=0.0;
        else
        this->price=price;
    }
    double  getInvoiceAmount()
    {
        return (double)(price*quantity);
    }

};
int main(){
string des,no;
int quan;
double price;
cout<<endl<<"Enter description : ";
getline(cin,des);
cout<<endl<<"Enter product Number : ";
getline(cin,no);
cout<<endl<<"Enter quantity : ";
cin>>quan;
cout<<endl<<"Enter price : ";
cin>>price;
Invoice A001(no,des,quan,price);
cout<<endl<<endl<<"Invoice "<<endl;
cout<<"Quantity : "<<quan<<endl
<<"Price : "<<price<<endl
<<"Total : "<<A001.getInvoiceAmount(); 

return 0;
}