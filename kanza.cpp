#include <iostream>
using namespace std;

class Account
{
protected:
   double balance;

public:
   Account(double bal)
   {
      balance = bal;
      if (balance < 0.0)
      {
         balance = 0.0;
         cout << "Initial balance is invalid!!" << endl;
      }
   }
   virtual void Credit(double cred)
   {
      balance = balance + cred;
   }
   void Debit(double deb)
   {

      if (deb > balance)
      {
         cout << "Debit amount exceeded account balance." << endl;
      }
      else
      {
         balance = balance - deb;
      }
   }
   double getBalance()
   {
      return (balance);
   }
};

class SavingsAccount : public Account
{

   double interest;

public:
   SavingsAccount(double bal, double int_rate) : Account(bal)
   {
      interest = int_rate;
   }
   double calculateInterest()
   {
      return (interest / 100) * balance;
   }
};

class CheckingAccount : public Account
{

   double fee; //fee charged per transaction
public:
   CheckingAccount(double bal, double f_am) : Account(bal)
   {
      fee = f_am;
   }
   void Credit(double cred)
   {
      balance = balance + cred;
      balance -= fee;
   }
   bool Debit(double deb)
   {
      if (deb > balance)
      {
         cout << "Debit amount exceeded account balance." << endl;
         return false;
      }
      else
      {
         balance = balance - deb;
         return true;
      }
   }
   void FeeDeduct(bool t)
   {
      if (t)
         balance -= fee;
   }
};
int main()
{
   int choose;
   cout<<"PRESS 1 FOR SavingsAccount\nPRESS 2 FOR CheckingAccount"<<endl;
   cin>>choose;
   double bal, rate, fee;
   if(choose==1)
   {cout << endl
        << "SAVING ACCOUNT \nENTER BALANCE IN $ : ";
   cin >> bal;
   cout << endl
        << "ENTER INTEREST RATE : ";
   cin >> rate;
   SavingsAccount SA(bal, rate);
   cout << endl
        << "CUREENT BALANCE : " << SA.getBalance() << "$";
   cout << endl
        << "INTEREST RATE ON CURRENT BALANCE IS : " << SA.calculateInterest();
   cout << endl
        << "ENTER THE AMOUNT YOU WANT TO CREDIT : ";
   cin >> bal;
   SA.Credit(bal);
   cout << endl
        << "CUREENT BALANCE AFTER CREDIT OF AMOUNT  : " << bal << "$ IS : " << SA.getBalance() << "$";
   cout << endl
        << "INTEREST RATE ON CURRENT BALANCE IS : " << SA.calculateInterest();
   cout << endl
        << "ENTER THE AMOUNT YOU WANT TO DEBIT : ";
   cin >> bal;
   SA.Debit(bal);
   cout << endl
        << "CUREENT BALANCE AFTER DEBIT OF AMOUNT  : " << bal << "$ IS : " << SA.getBalance() << "$";
   cout << endl
        << "INTEREST RATE ON CURRENT BALANCE IS : " << SA.calculateInterest();
   }
   else
  {
   cout << endl
        << "SAVING ACCOUNT \nENTER BALANCE IN $ : ";
   cin >> bal;
   cout << endl
        << "ENTER INTEREST FEE : ";
   cin >> fee;
   CheckingAccount CA(bal, fee);
   cout << endl
        << "CUREENT BALANCE : " << CA.getBalance() << "$";
   cout << endl
        << "ENTER THE AMOUNT YOU WANT TO CREDIT : ";
   cin >> bal;
   CA.Credit(bal);
   cout << endl
        << "CUREENT BALANCE AFTER CREDIT OF AMOUNT  : " << bal << "$ AND FEE DEDUCTION OF " << fee << "$ IS : " << CA.getBalance() << "$";
   cout << endl
        << "ENTER THE AMOUNT YOU WANT TO DEBIT : ";
   cin >> bal;
   bool isdebit=CA.Debit(bal);
   CA.FeeDeduct(isdebit);
   cout << endl
        << "CUREENT BALANCE AFTER DEBIT OF AMOUNT  : " << bal << "$ AND FEE DEDUCTION OF " << fee << "$ IS : " << CA.getBalance() << "$";
      }
}