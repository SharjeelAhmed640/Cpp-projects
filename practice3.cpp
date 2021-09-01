#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Message{
    string pegaam;
    public:
    Message(string temp="-")
    {
        this->pegaam=temp;
    }
    void print()
    {
        cout<<this->pegaam<<endl;
    }
    void print(string temp)
    {
        cout<<this->pegaam+" "+temp<<endl;
    }
};
class Package{
    protected:
string name_s,address_s,city_s,state_s,name_r,address_r,city_r,state_r;
int zipcode_r,zipcode_s;
double weight,cost;
    public:
    Package(string name_s,string address_s,string city_s,string state_s,string name_r,string address_r,string city_r,string state_r,int zipcode_r,int zipcode_s,double weight,double cost){
        this->name_s=name_s;
        this->state_s=state_s;
        this->zipcode_s=zipcode_s;
        this->city_s=city_s;
        this->address_s=address_s;

        this->name_r=name_r;
        this->state_r=state_r;
        this->zipcode_r=zipcode_r;
        this->city_r=city_r;
        this->address_r=address_r;

        this->weight=weight;
        if(weight<0)
        this->weight=0;

        this->cost=cost;
        if(cost<0)
        this->cost=0;
    }
    virtual double CalculateCost()=0;

};
class TwoDayPackageDelivery: public Package{
    double fee;
    public:
    TwoDayPackageDelivery(double fee,string name_s,string address_s,string city_s,string state_s,string name_r,string address_r,string city_r,string state_r,int zipcode_r,int zipcode_s,double weight,double cost):Package( name_s, address_s, city_s, state_s, name_r, address_r, city_r, state_r, zipcode_r, zipcode_s, weight, cost)
    {
        this->fee=fee;
        if(fee<0)
        this->fee=0;
    }
    double CalculateCost(){
        return (weight*cost)+fee;
    }

};
class OverNightPackageDelivery: public Package{
    double additional_cost;
    public:
    OverNightPackageDelivery(double additional_cost,string name_s,string address_s,string city_s,string state_s,string name_r,string address_r,string city_r,string state_r,int zipcode_r,int zipcode_s,double weight,double cost):Package( name_s, address_s, city_s, state_s, name_r, address_r, city_r, state_r, zipcode_r, zipcode_s, weight, cost)
    {
        this->additional_cost=additional_cost;
        if(additional_cost<0)
        this->additional_cost=0;
    }
    double CalculateCost(){
        return (weight*cost)+(weight*additional_cost);
    }

};

class Accounts{
    protected:
    double balance;
    public:
    Accounts(double balance)
    {
        this->balance=balance;
        if(balance<0)
        {
            this->balance=0.0;
            cout<<"Initial balance should be more than 0.00 Pkr"<<endl;
        }

    }
    void virtual Credit(double const bal)
    {
        this->balance+bal;
        cout<<endl<<"Sucessfully credited"<<endl;
    }
    bool const virtual Debit(double bal)
    {
        if(bal>balance)
        {
            cout<<endl<<"Debit amount exceeded account balance"<<endl;
        }
        else
        {
            balance-bal;
            return true;
        }
    }
    double const virtual getbalance()
    {
        return balance;
    }

};
class SavingAccount:public Accounts{
    float interst_rate;
    public:
    SavingAccount(float rate,double bal):Accounts(bal)
    {
        this->interst_rate=rate;
    }
    double const calculateInterest(){
        return balance*(interst_rate/100);
    }
};
class CheckingAccount:public Accounts{};
int main()
{
/*Message pegam("lorooooooooo");
pegam.print();
pegam.print("mera");*/

OverNightPackageDelivery O(25,"sharjeel","karachi","karachi","pakistan","Ali","karachi","karachi","pakistan",123,124,50,5);
cout<<O.CalculateCost()<<endl;
TwoDayPackageDelivery T(25,"sharjeel","karachi","karachi","pakistan","Ali","karachi","karachi","pakistan",123,124,50,5);
cout<<T.CalculateCost();
return 0;
}