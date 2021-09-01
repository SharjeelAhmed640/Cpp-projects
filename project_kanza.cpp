#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;
void pause()
{   ::std::cout<<"\nPress ENTER to continue.";
    ::std::cin.sync();
    if(::std::cin.get()!='\n')
        ::std::cin.ignore(0xFFFFFFFF,'\n');
}
class sign_in_up
{

protected:
    string fullname, email, pass, Number, address, nic;

public:
    sign_in_up()
    {
        fullname = "-";
        email = "-";
        pass = "-";
        Number = "-";
        address = "-";
        nic = "-";
    }
    void CreateAcc(string fullname, string email, string pass, string Number, string address, string nic)
    {
        this->fullname = fullname;
        bool check = false;
        this->email = email;
        /* while (check != true)
        {
            for (int i = 0; i < this->email.length(); i++)
            {
                if (email[i] == '@')
                {
                    check = true;
                    break;
                }
            }
            if (check == true)
                break;
            else
            {

                cout << "Enter valid email address : ";

                cin >> this->email;
            }
        }*/
        this->pass = pass;
        this->Number = Number;
        check = false;
        /*  while (check != true)
        {
            for (int i = 0; i < this->Number.length(); i++)
            {
                if (this->Number[i] >= '0' && this->Number[i] <= '9')
                    check = true;
                else
                {
                    check = false;
                    break;
                }
            }
            if (this->Number.length() != 11)
                check = false;
            else if (check == false)
            {
                cout << "Enter valid mobile number : ";
                cin.ignore();
                cin >> this->Number;
            }
            else
                break;
        }*/
        this->address = address;
        this->nic = nic;
        check = false;
        /* while (check != true)
        {
            for (int i = 0; i < this->nic.length(); i++)
            {
                if (this->nic[i] >= '0' && this->nic[i] <= '9')
                    check = true;
                else
                {
                    check = false;
                    break;
                }
            }
            if (this->nic.length() != 13)
                check = false;
            else if (check == false)
            {
                cout << "Enter valid NIC number : ";
                cin >> this->nic;
            }
            else
                break;
        }*/
        this->Write();
    }
    virtual void Write()
    {
        cout << "Your account has been created successfully" << endl;
        ofstream file;
        file.open("Login.txt", ios::app);
        file << fullname << endl
             << email << endl
             << pass << endl
             << Number << endl
             << address << endl
             << nic << endl;
        file.close();
    }
    virtual bool login(string email, string pass) = 0;
    void changepass(string email, string pass)
    {
        string newpass;
        ifstream file;
        file.open("Login.txt", ios::ate);
        file.seekg(0);
        fstream temp;
        temp.open("TEMP.txt", ios::out);
        while (getline(file, this->fullname) && getline(file, this->email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (this->email == email && this->pass == pass)
            {
                cout << "Enter new password : ";
                cin >> newpass;
                temp << this->fullname << endl
                     << this->email << endl
                     << newpass << endl
                     << this->Number << endl
                     << this->address << endl
                     << this->nic << endl;
            }
            else
            {
                temp << this->fullname << endl
                     << this->email << endl
                     << this->pass << endl
                     << this->Number << endl
                     << this->address << endl
                     << this->nic << endl;
            }
        }
        file.close();
        temp.close();

        if (remove("Login.txt") != 1)
            cout << "Password changed succesfully" << endl;
        else
        {
            cout << "Password not changed" << endl;
        }

        if (rename("TEMP.txt", "Login.txt") != 0)
            perror("Error moving file");
    }
};

class bid
{
protected:
    string Itemname, description, posting_date, deadline_to_bid, email;
    double minbid;
    double highoffer;
    int bidid;
    bool visible = false;

public:
    bid()
    {
        this->Itemname = "-";
        this->description = "-";
        this->posting_date = "-";
        this->deadline_to_bid = "-";
        this->email = "-";
        this->highoffer = 0;
        this->minbid = 0.0;
        this->visible = true;
    }
    void setbid(string itemname, string description, string posting_date, string deadline_to_bid, string email, double highoffer, double minbid, bool vivible)
    {
        this->Itemname = itemname;
        this->description = description;
        this->posting_date = posting_date;
        this->deadline_to_bid = deadline_to_bid;
        bool check = false;
        this->email = email;
        /* while (check != true)
        {
            for (int i = 0; i < this->email.length(); i++)
            {
                if (email[i] == '@')
                {
                    check = true;
                    break;
                }
            }
            if (check == true)
                break;
            else
            {

                cout << "Enter valid email address : ";

                cin >> this->email;
            }
        }*/
        this->highoffer = highoffer;
        this->minbid = minbid;
        this->bidid = BIDID();
        this->visible = visible;
        writebid();
    }
    int BIDID()
    {
        ifstream file;
        file.open("bid.txt", ios::ate);
        if (!file)
        {
            file.close();
            return 1000;
        }
        else if (file.tellg() == 0)
        {
            file.close();
            return 1000;
        }
        else
        {
            file.seekg(0);
            while (getline(file, this->Itemname) && getline(file, this->description) && getline(file, this->posting_date) && getline(file, this->deadline_to_bid) && getline(file, this->email) && file >> this->highoffer && file >> this->minbid && file >> this->bidid && file >> this->visible)
                ;
            file.close();
            return this->bidid += 1;
        }
    }
    void writebid()
    {
        cout << "Your bid was saved" << endl;
        ofstream file;
        file.open("biditem.txt", ios::app);
        file << this->Itemname << endl
             << this->description << endl
             << this->posting_date << endl
             << this->deadline_to_bid << endl
             << this->email << endl
             << this->highoffer << endl
             << this->minbid << endl
             << this->bidid << endl
             << this->visible << endl;
        file.close();
    }
};
class seller : public sign_in_up, public bid
{
public:
    void viewhisbids()
    {
        string email, pass;
        cout << "Enter email : ";
        cin >> email;
        bool check = false;
        /* for (int i = 3; i >= 0; i--)
        {
            while (check != true)
            {
                for (int i = 0; i < email.length(); i++)
                {
                    if (email[i] == '@')
                    {
                        check = true;
                        break;
                    }
                }
                if (check == true)
                    break;
                else
                {

                    cout << "Enter valid email address : ";

                    cin >> email;
                }
            }
            cout << "You have " << i << " attemps remaining" << endl;
        }*/
        cout << "enter password : ";
        cin >> pass;
        if (login(email, pass))
        {
            ifstream file;
            file.open("biditem.txt", ios::ate);
            file.seekg(0);
            cout << "Item name" << setw(15) << "Description" << setw(15) << "Psoting date" << setw(15) << "Bid deadline" << setw(15) << "email" << setw(15) << "Offer" << setw(15) << "Min bid" << setw(15) << "Bid id"
                 << "sold or not" << endl;
            while (getline(file, this->Itemname) && getline(file, this->description) && getline(file, this->posting_date) && getline(file, this->deadline_to_bid) && getline(file, bid::email) && file >> this->highoffer && file >> this->minbid && file >> this->bidid && file >> this->visible)
            {
                if (sign_in_up::email == bid::email)
                    cout << setw(15) << this->Itemname << setw(15)
                         << this->description << setw(15)
                         << this->posting_date << setw(15)
                         << this->deadline_to_bid << setw(15)
                         << bid::email << setw(15)
                         << this->highoffer << setw(15)
                         << this->minbid << setw(15)
                         << this->bidid << setw(15);
                if (visible == true)
                    cout << "Unsold" << setw(15) << endl;
                else
                {
                    cout << "sold" << setw(15) << endl;
                }
            }
        }
    }
    bool login(string emails, string pass)
    {

        ifstream file;
        file.open("Login.txt", ios::ate);
        file.seekg(0);
        while (getline(file, this->fullname), getline(file, sign_in_up::email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (sign_in_up::email == emails && this->pass == pass)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};
class buyer : public sign_in_up, public bid
{
public:
    bool login(string emails, string pass)
    {

        ifstream file;
        file.open("Login.txt", ios::ate);
        file.seekg(0);
        while (getline(file, this->fullname), getline(file, sign_in_up::email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (sign_in_up::email == emails && this->pass == pass)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
   void viewallbids() // view all the  bids
    {
        string Itemname, description;
        bool visible;
        ifstream file;
        file.open("biditem.txt");
        
        cout << "Item name" << setw(15) << "Description" << setw(15) << "Psoting date" << setw(15) << "Bid deadline" << setw(15) << "email" << setw(15) << "Offer" << setw(15) << "Min bid" << setw(15) << "Bid id" << setw(15)
             << "sold or not" << endl;

        while (getline(file,Itemname))
        {
            //getline(file,Itemname);
            cout << Itemname << setw(20);

            getline(file,description);
               cout  << description << setw(15);

                 getline(file,Itemname);
               cout  << Itemname << setw(15);

                 getline(file,Itemname);
               cout  << Itemname << setw(15);

                 getline(file,Itemname);
               cout  << Itemname << setw(15);

                 getline(file,Itemname);
               cout  << Itemname << setw(15);

                 getline(file,Itemname);
               cout  << Itemname << setw(15);

                 getline(file,Itemname);
                cout << Itemname << setw(15);
                 
                 getline(file,Itemname);
                 int visible=stoi(Itemname);
            if (visible == 1)
                cout << "Unsold" << endl;
            else
            {
                cout << "sold"  << endl;
            }
        }
        file.close();
    }
    void dobid(double bid, int bidid) //bid by the buyer if bid is higher than lst
    //bid then change the highest offer by current bid and if the current bid greater
    //than min bid value than change visibllity to false(sold)
    {
        string emails, pass;
        cout << "enter email : ";
        cin >> emails;
        cout << "Enter password : ";
        cin >> pass;
        if (login(emails, pass))
        {

            ifstream file;
            file.open("biditem.txt", ios::ate);
            file.seekg(0);
            fstream temp;
            temp.open("TEMP.txt", ios::out);
            while (getline(file, this->Itemname) && getline(file, this->description) && getline(file, this->posting_date) && getline(file, this->deadline_to_bid) && getline(file, bid::email) && file >> this->highoffer && file >> this->minbid && file >> this->bidid && file >> this->visible)
            {
                if (this->visible == true && this->bidid == bidid)
                {
                    if (this->highoffer < bid)
                    {
                        this->highoffer = bid;
                    }
                    if (this->highoffer > this->minbid)
                    {

                        goto dosave;
                    }
                }
            dosave:
                if ((this->highoffer > this->minbid) && (this->bidid == bidid) && (this->visible = true))
                {
                    string number, pass, emails, address, nic;
                    cout << "Enter email address : ";
                    cin >> emails;
                    cout << "Enter number : ";
                    cin >> number;
                    cout << "Enter address : ";
                    cin.ignore();
                    getline(cin, address);
                    cout << "Enter NIC : ";
                    cin >> nic;
                    ofstream bidfile;
                    bidfile.open("bidcomp.txt", ios::app);
                    bidfile << emails << endl
                            << number << endl
                            << address << endl
                            << nic << endl
                            << this->Itemname << endl
                            << this->description << endl
                            << this->posting_date << endl
                            << bid::email << endl
                            << this->highoffer << endl
                            << this->minbid << endl
                            << this->bidid << endl;
                    bidfile.close();
                }
                if (bid > this->minbid)
                {
                    temp << this->Itemname << endl
                         << this->description << endl
                         << this->posting_date << endl
                         << this->deadline_to_bid << endl
                         << bid::email << endl
                         << this->highoffer << endl
                         << this->minbid << endl
                         << this->bidid << endl
                         << false << endl;
                }
                else
                {
                    temp << this->Itemname << endl
                         << this->description << endl
                         << this->posting_date << endl
                         << this->deadline_to_bid << endl
                         << bid::email << endl
                         << this->highoffer << endl
                         << this->minbid << endl
                         << this->bidid << endl
                         << true << endl;
                }
            }

            temp.close();
            file.close();
            if (remove("biditem.txt") != 1)
                //cout << "You have win the bid" << endl;

                if (rename("TEMP.txt", "biditem.txt") != 0)
                    perror("Error moving file");
        }
        else
        {
            cout << "You have entered wrong email/password" << endl;
        }
    }
};
class admin : public sign_in_up, public bid
{
    bool isadmin = false;

public:
    void createaccount(string fullname, string email, string pass, string Number, string address, string nic)
    {
        ofstream file("admin.txt", ios::app);
        file << fullname << endl
             << email << endl
             << pass << endl
             << Number << endl
             << address << endl
             << nic << endl;
        file.close();
    }
    void changepass(string email, string pass)
    {
        string newpass;
        ifstream file;
        file.open("admin.txt", ios::ate);
        file.seekg(0);
        fstream temp;
        temp.open("TEMP.txt", ios::out);
        while (getline(file, this->fullname) && getline(file, this->sign_in_up::email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (this->sign_in_up::email == email && this->pass == pass)
            {
                cout << "Enter new password : ";
                cin >> newpass;
                temp << this->fullname << endl
                     << this->sign_in_up::email << endl
                     << newpass << endl
                     << this->Number << endl
                     << this->address << endl
                     << this->nic << endl;
            }
            else
            {
                temp << this->fullname << endl
                     << this->sign_in_up::email << endl
                     << this->pass << endl
                     << this->Number << endl
                     << this->address << endl
                     << this->nic << endl;
            }
        }
        file.close();
        temp.close();

        if (remove("Login.txt") != 1)
            cout << "Password changed succesfully" << endl;
        else
        {
            cout << "Password not changed" << endl;
        }

        if (rename("TEMP.txt", "Login.txt") != 0)
            perror("Error moving file");
    }
    bool login(string emails, string pass)
    {

        ifstream file;
        file.open("admin.txt", ios::ate);
        file.seekg(0);
        while (getline(file, this->fullname), getline(file, sign_in_up::email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (sign_in_up::email == emails && this->pass == pass)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    admin()
    {
    }
    void viewallsolditems()
    {
        string email, Number, address, nic, Itemname, description, posting_date, emailb, emails, highoffer, minbid, bidid;
        // if (isadmin == true)
        {
            ifstream file;
            file.open("bidcomp.txt", ios::ate);
            file.seekg(0);
            cout << "Email" << setw(15) << "Number" << setw(15) << "Address" << setw(15) << "NIC" << setw(15)
                 << "Itemname" << setw(15) << "Description" << setw(15) << "Post date" << setw(15) << "Email" << setw(15)
                 << "Offer" << setw(15) << "Min Price" << setw(15) << "ID" << endl;
            while (getline(file, emailb), getline(file, Number), getline(file, address), getline(file, nic), getline(file, Itemname), getline(file, description), getline(file, posting_date), getline(file, emails), file >> highoffer, file >> minbid, file >> bidid)
            {
                cout << emailb << setw(15)
                     << Number << setw(15)
                     << address << setw(15)
                     << nic << setw(15)
                     << Itemname << setw(15)
                     << description << setw(15)
                     << posting_date << setw(15)
                     << emails << setw(15)
                     << highoffer << setw(15)
                     << minbid << setw(15)
                     << bidid << setw(15) << endl;
            }
            file.close();
        }
    }
    void viewactivebids() // view all the  bids
    {
        string email, Number, address, nic, Itemname, description, posting_date, emailb, emails, highoffer, minbid, bidid;
        bool visible;

        // if (isadmin == true)
        
            ifstream file;
            file.open("biditem.txt", ios::ate);
            file.seekg(0);
            cout << "Item name" << setw(15) << "Description" << setw(15) << "Psoting date" << setw(15) << "Bid deadline" << setw(15) << "email" << setw(15) << "Offer" << setw(15) << "Min bid" << setw(15) << "Bid id" << setw(15)
                 << "sold or not" << endl;
            while (getline(file, Itemname) && getline(file, description) && getline(file, posting_date) && getline(file, deadline_to_bid) && getline(file, emails) && file >> highoffer && file >> minbid && file >> bidid && file >> visible)
            {
                if (visible == true)
                    cout << Itemname << setw(15)
                         << description << setw(15)
                         << posting_date << setw(15)
                         << deadline_to_bid << setw(15)
                         << emails << setw(15)
                         << highoffer << setw(15)
                         << minbid << setw(15)
                         << bidid << setw(15);
                if (visible == true)
                    cout << "Unsold" << setw(15) << endl;
                else
                {
                    cout << "sold" << setw(15) << endl;
                }
            }
            file.close();
        
    }
    void viewSOLDbids() // view all the  bids
    {
        string email, Number, address, nic, Itemname, description, posting_date, emailb, emails, highoffer, minbid, bidid;
        bool visible;
        // if (isadmin == true)
        {
            ifstream file;
            file.open("biditem.txt", ios::ate);
            file.seekg(0);
            cout << "Item name" << setw(15) << "Description" << setw(15) << "Psoting date" << setw(15) << "Bid deadline" << setw(15) << "email" << setw(15) << "Offer" << setw(15) << "Min bid" << setw(15) << "Bid id" << setw(15)
                 << "sold or not" << endl;
            while (getline(file, Itemname) && getline(file, description) && getline(file, posting_date) && getline(file, deadline_to_bid) && getline(file, emails) && file >> highoffer && file >> minbid && file >> bidid && file >> visible)
            {
                if (visible == false)
                    cout << Itemname << setw(15)
                         << description << setw(15)
                         << posting_date << setw(15)
                         << deadline_to_bid << setw(15)
                         << emails << setw(15)
                         << highoffer << setw(15)
                         << minbid << setw(15)
                         << bidid << setw(15);
                if (visible == true)
                    cout << "Unsold" << setw(15) << endl;
                else
                {
                    cout << "sold" << setw(15) << endl;
                }
            }
            file.close();
        }
    }
    void viewallusers()
    {
        //  if (isadmin == true)
        {
            ifstream file;
            file.open("Login.txt", ios::ate);
            file.seekg(0);
            cout << "Name" << setw(15) << "Email" << setw(15) << "Number" << setw(15) << "Address" << setw(15) << "NIC" << setw(15) << endl;
            while (getline(file, this->fullname), getline(file, sign_in_up::email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
            {
                cout << this->fullname << setw(15)
                     << sign_in_up::email << setw(15)
                     << this->Number << setw(15)
                     << this->address << setw(15)
                     << this->nic << setw(15) << endl;
            }
            file.close();
        }
    }
};
void sellerfuntion()
{
    system("CLS");
    seller *S = new seller;
    string itemname, description, posting_date, deadline_to_bid, email;
    double highoffer, minbid;
    int bidid;
    bool vivible;
    string fullname, pass, Number, address, nic;
    cout << "Press 1 for login\nPress 2 for signup" << endl;
    int select;
    cin >> select;
    if (select == 2)
    {
        system("CLS");
        cout << "Enter email address : ";
        cin >> email;

        cout << "Enter password : ";
        cin >> pass;

        cout << "Enter number : ";
        cin >> Number;

        cout << "Enter nic : ";
        cin >> nic;
        cin.ignore();
        cout << "Enter address : ";
        getline(cin, address);

        cout << "Enter Full name : ";
        getline(cin, fullname);
        S->CreateAcc(fullname, email, pass, Number, address, nic);
    }
    else if (select == 1)
    {
        system("CLS");
        cout << "Enter email address : ";
        cin >> email;
        cout << "Enter password : ";
        cin >> pass;
        if (S->login(email, pass) == true)
        {
            cout << "LOGIN SUCCESSFULL " << endl;

            cout << "press 1 for create new account" << endl
                 << "press 2 for login" << endl
                 << "Press 3 for change password" << endl
                 << "press 4 for bid" << endl
                 << "press 5 for view bids" << endl;
            int choose;
            cin >> choose;
            switch ((choose))
            {
            case 1:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;

                cout << "Enter password : ";
                cin >> pass;

                cout << "Enter number : ";
                cin >> Number;

                cout << "Enter nic : ";
                cin >> nic;
                cin.ignore();
                cout << "Enter address : ";
                getline(cin, address);

                cout << "Enter Full name : ";
                getline(cin, fullname);
                S->CreateAcc(fullname, email, pass, Number, address, nic);
                cout << "Press any key to continue" << endl;
                cin.get();
                pause();
                break;
            }
            case 2:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;
                cout << "Enter password : ";
                cin >> pass;
                if (S->login(email, pass) == true)
                {
                    cout << "LOGIN SUCCESSFULL " << endl;
                }
                else
                    cout << "ERROR" << endl;
                cout << "Press any key to continue" << endl;
                cin.get();
                pause();
                break;
            }
            case 3:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;
                cout << "Enter password : ";
                cin >> pass;
                S->changepass(email, pass);
                cout << "Press any key to continue" << endl;
                cin.get();
                pause();
                break;
            }
            case 4:
            {
                system("CLS");
                cout << "Enter posting date : ";
                cin >> posting_date;
                cout << "Enter deadline to bid : ";
                cin >> deadline_to_bid;
                cout << "Enter email : ";
                cin >> email;
                highoffer = 0;
                cout << "Enter min price/bid : ";
                cin >> minbid;
                vivible = true;
                cin.ignore();
                cout << "Enter item name : ";
                getline(cin, itemname);

                cout << "Enter description : ";
                getline(cin, description);
                S->setbid(itemname, description, posting_date, deadline_to_bid, email, highoffer, minbid, vivible);
                cout << "Press any key to continue" << endl;
                cin.get();
                pause();
                break;
            }
            case 5:
            {
                system("CLS");
                S->viewhisbids();
                cout << "Press any key to continue" << endl;
                cin.get();
                pause();
            }
            default:
                break;
            }
        }
        else
        {
            cout << "Wrong email/password" << endl;
        }
    }
}

void buyerfuction()
{
    system("CLS");
    buyer *B = new buyer;
    string fullname, email, pass, Number, address, nic;
    cout << "Press 1 for log in\nPress 2 for sign up" << endl;
    int select;
    cin >> select;
    if (select == 2)
    {
        system("CLS");
        cout << "Enter email address : ";
        cin >> email;

        cout << "Enter password : ";
        cin >> pass;

        cout << "Enter number : ";
        cin >> Number;

        cout << "Enter nic : ";
        cin >> nic;
        cin.ignore();
        cout << "Enter address : ";
        getline(cin, address);

        cout << "Enter Full name : ";
        getline(cin, fullname);
        B->CreateAcc(fullname, email, pass, Number, address, nic);
    }
    else if (select == 1)
    {
        system("CLS");
        cout << "Enter email address : ";
        cin >> email;
        cout << "Enter password : ";
        cin >> pass;
        if (B->login(email, pass))
        {
            cout << "LOGIN SUCCESSFULL " << endl;

            cout << "Press 1 for create account " << endl
                 << "Press 2 for login " << endl
                 << "press 3 for change password : " << endl
                 << "press 4 for bidding " << endl
                 << "press 5 for view all bids/products  " << endl;
            int choose;
            cin >> choose;
            switch (choose)
            {
            case 1:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;

                cout << "Enter password : ";
                cin >> pass;

                cout << "Enter number : ";
                cin >> Number;

                cout << "Enter nic : ";
                cin >> nic;
                cin.ignore();
                cout << "Enter address : ";
                getline(cin, address);

                cout << "Enter Full name : ";
                getline(cin, fullname);
                B->CreateAcc(fullname, email, pass, Number, address, nic);
                pause();
                break;
            }
            case 2:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;
                cout << "Enter password : ";
                cin >> pass;
                if (B->login(email, pass))
                {
                    cout << "LOGIN SUCCESSFULL " << endl;
                }
                else
                    cout << "ERROR" << endl;
                pause();
                break;
            }
            case 3:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;
                cout << "Enter password : ";
                cin >> pass;
                B->changepass(email, pass);
                pause();
                break;
            }
            case 4:
            {
                system("CLS");
                B->viewallbids();
                int id;
                double bidprice;
                cout << "Enter bid id : ";
                cin >> id;
                cout << "Enter bid : ";
                cin >> bidprice;
                B->dobid(bidprice, id);
               pause();
                break;
            }
            case 5:
            {
                system("CLS");
                B->viewallbids();
              pause();
            }
            default:
                break;
            }
        }
        else
        {
            cout << "Wrong email/pass" << endl;
        }
    }
}
void Adminfunction()
{
    system("CLS");
    admin *A = new admin;
    string fullname, email, pass, Number, address, nic;
    cout << "press 1 for login \npress 2 for signup" << endl;
    int select;
    cin >> select;
    if (select == 2)
    {
        system("CLS");
        cout << "Enter email address : ";
        cin >> email;

        cout << "Enter password : ";
        cin >> pass;

        cout << "Enter number : ";
        cin >> Number;

        cout << "Enter nic : ";
        cin >> nic;
        cin.ignore();
        cout << "Enter address : ";
        getline(cin, address);

        cout << "Enter Full name : ";
        getline(cin, fullname);
        A->createaccount(fullname, email, pass, Number, address, nic);
    }
    else if (select == 1)
    {
        system("CLS");
        cout << "Enter email : ";
        cin >> email;
        cout << "Enter password : ";
        cin >> pass;
        if (A->login(email, pass))
        {
            cout << "Press 1 for create account " << endl
                 << "Press 2 for login " << endl
                 << "press 3 for change password : " << endl
                 << "press 4 for active bids " << endl
                 << "press 5 for view all sold bids details  " << endl
                 << "Press 6 for View all users" << endl
                 << "Press 7 for view all sold bids " << endl;
            int choose;
            cin >> choose;

            switch (choose)
            {
            case 1:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;

                cout << "Enter password : ";
                cin >> pass;

                cout << "Enter number : ";
                cin >> Number;

                cout << "Enter nic : ";
                cin >> nic;
                cin.ignore();
                cout << "Enter address : ";
                getline(cin, address);

                cout << "Enter Full name : ";
                getline(cin, fullname);
                A->createaccount(fullname, email, pass, Number, address, nic);
               pause();
                break;
            }
            case 2:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;
                cout << "Enter password : ";
                cin >> pass;
                if (A->login(email, pass))
                {
                    cout << "LOGIN SUCCESSFULL " << endl;
                }
                else
                    cout << "ERROR" << endl;
               pause();
                break;
            }
            case 3:
            {
                system("CLS");
                cout << "Enter email address : ";
                cin >> email;
                cout << "Enter password : ";
                cin >> pass;
                A->changepass(email, pass);
              pause();
                break;
            }
            case 4:
            {
                system("CLS");
                A->viewactivebids();
               pause();
                break;
            }
            case 5:
            {
                system("CLS");
                A->viewallsolditems(); //details of sold bids
              pause();
                break;
            }
            case 6:
            {
                system("CLS");
                A->viewallusers();
               pause();
                break;
            }
            case 7:
            {
                system("CLS");
                A->viewSOLDbids();
              pause();
                break;
            }
            default:
            {
                cout << "Wrong input" << endl;
            }
            }
        }
    }
    else
        cout << "You have entered worng email/password" << endl;
}
int main()
{
    cout << "WELCOME TO ******" << endl;
    int choose;
    while (1)
    {
        cout << "press 1 for login as seller" << endl
             << "Press 2 for login as buyer" << endl
             << "Press 3 for log in as admin" << endl
             << "Press 4 to exit" << endl;
        cin >> choose;

        switch (choose)
        {
        case 1:
        {
            sellerfuntion();
            break;
        }
        case 2:
        {
            buyerfuction();
            break;
        }
        case 3:
            Adminfunction();
            break;
        case 4:
            goto end;
            break;
        default:
            cout << "Enter valid input" << endl;
            break;
        }
        system("CLS");
    }
end:
    cout << "**********THANK YOU************" << endl;
    cout << "Press any key to continue" << endl;
    pause();
    return 0;
}