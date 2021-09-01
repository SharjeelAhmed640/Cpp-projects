#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
/*The interestaccount class adds interest for every deposit,assume a default of 30%.
1. The charging account class charges a default fee of $3 for every withdrawal.
2. Transfer method of aci class takes two parameters,amount to be transfer and object of class
in which we have to transfer that amount.
Activity

3. Make parameterized constructor, and default constructor to take user input for all data
members.
4. Make a driver program to test all functionalities.*/

class Account
{
protected:
    double balance;

public:
    Account(double b)
    {
        balance = b;
        if (b < 0)
            balance = 0;
    }
    void deposite(const double d)
    {
        balance = d;
    }
    bool withdraw(double const w)
    {
        if (w < balance)
        {
            balance -= w;
            return true;
        }
        else
            return false;
    }
    void const checkbalance()
    {
        cout << "current balance : " << balance << endl;
    }
};
class InterestAccount : public virtual Account
{
protected:
    double interest; //30%
public:
    InterestAccount(double i, double b) : Account(b)
    {
        interest = i;
        if (i < 0)
            interest = 20;
    }
    void deposite(const double d)
    {
        balance = d + (d * interest);
    }
};
class ChargingAccount : public virtual Account
{
protected:
    double fee;

public:
    ChargingAccount(double f, double b) : Account(b)
    {
        fee = f;
        if (f < 0)
            fee = 1;
    }
    bool withdraw(double const w)
    {
        if (w < balance)
        {

            balance -= w - fee;
            return true;
        }
        else
            return false;
    }
};
class ACI : public ChargingAccount, public InterestAccount
{

public:
    ACI(double f, double i, double b) : Account(b), InterestAccount(i, b), ChargingAccount(f, b)
    {
    }
    void transfer(double ammount, Account a)
    {
        a.deposite(ammount);
    }
    void transfer(double ammount, ChargingAccount c)
    {
        c.deposite(ammount);
    }
    void transfer(double ammount, InterestAccount i)
    {
        i.deposite(ammount);
    }
};
int main()
{
    
    double bal,fee;
    cout << "Enter opening balance(charging account) : ";
    cin >> bal;
    ChargingAccount ali(4,bal);
    cout << "Enter opening balance(account) : ";
    cin >> bal;
    Account sharjeel(bal);
    sharjeel.checkbalance();
    cout << "Press 1 for view current balance\nPress 2 for Deposite\nPress 3 for Withdraw\nPress 4 for funds transfer";
    int choose;
    cin>>choose;
    switch (choose)
    {
    case 1:
        sharjeel.checkbalance();
        break;
    case 2:
        cout << "Enter deposite amount : ";
        cin >> bal;
        sharjeel.deposite(bal);
        break;
    case 3:
        cout << "Enter withdraw amount : ";
        cin >> bal;
        if (sharjeel.withdraw(bal))
            cout << "Withdraw succesfull" << endl;
        else
            cout << "Withdraw unsuccesfull" << endl;\
        break;
    case 4:
        cout<<"Enter transfer amount : ";
        cin>>bal;
        if(sharjeel.withdraw(bal))
        {
            ACI transfer(0,0,0);
            transfer.transfer(bal,ali);
            cout<<"Transfer succesfully "<<endl;
            cout<<"Balance of ali(charging account) : " ; ali.checkbalance();
            cout<<"Balance of sharjeel(account) : " ; sharjeel.checkbalance();
        }
        else{
            cout<<"Transfer ammount exceed from current balance in aaccount "<<endl;
        }
        break;
    default:
        break;
    }
    return 0;
}