#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Account
{
    float c_bal;

public:
    Account(float c_bal)
    {
        this->c_bal = c_bal;
    }
    float getc_bal()
    {
        return c_bal;
    }
    void deposit(float dep)
    {
        c_bal += dep;
        cout << endl
             << "Current balance after deposit of " << dep << "$ is " << c_bal << endl;
    }
    void withdraw(float withdraw)
    {
        if(withdraw>c_bal)
        {c_bal -= withdraw;
        cout << endl
             << "Current balance after withdraw of " << withdraw << "$ is " << c_bal << endl;
        }
        else
        {
            cout<<endl<<"Does not have enough balance"<<endl<<"Current balance : "<<c_bal<<endl;
        }
    }
};
using namespace std;
int main()
{
    float c_bal;
    cout << "Enter current balance : ";
    cin >> c_bal;
    Account A(c_bal);
    cout << endl
         << "Choose 1 to view current balance\nChoose 2 for deposit\nChoose 3 for withdraw" << endl;
    int choose;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "Your currnet balance is : " << A.getc_bal();
        break;
    case 2:
        float dep;
        cout << endl
             << "Enter the amount you want to deposit : ";
        cin >> dep;
        A.deposit(dep);
        break;
    case 3:
        float withdraw;
        cout << endl
             << "Enter the amount you want to withdraw : ";
        cin >> dep;
        A.withdraw(withdraw);
        break;
    default:
        cout << endl
             << "Wrong input" << endl;
        break;
    }

    return 0;
}