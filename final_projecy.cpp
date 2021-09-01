#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;

class SignInFile //abstract class
{
protected:
    string email, pass, Number, address, nic;

public:
    SignInFile()
    {
        email = "-";
        pass = "-";
        Number = "-";
        address = "-";
        nic = "-";
    }
    void CreateAcc(string email, string pass, string Number, string address, string nic)
    {

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
            cout << "Enter valid email address : ";

            cin >> this->email;
        }*/
        this->pass = pass;
        this->Number = Number;
        /*check = false;
        while (check != true)
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
        /*check = false;*/
        /*while (check != true)
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
        ofstream file;
        file.open("LoginInfo.txt", ios::app);
        file << email << endl
             << pass << endl
             << Number << endl
             << address << endl
             << nic << endl;
        file.close();
    }

    virtual bool ShowSignINDetails(string Email, string Pass) = 0; //pure virtual function

    bool login(string email, string pass)
    {
        ifstream file;
        file.open("LoginInfo.txt", ios::ate);
        file.seekg(0);
        while (getline(file, this->email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (this->email == email && this->pass == pass)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};
class SignInSeller : public SignInFile //abstract class
{
protected:
    string shopname, NumberOfProducts, productName;
    int stock, productID;
    double price;
    bool ByZidellos;

public:
    SignInSeller()
    {
        this->shopname = "-";
        this->pass = "-";
        this->NumberOfProducts = "-";
        this->productName = "-";
        this->stock = 0;
        this->productID = 0;
        this->price = 0.0;
        this->ByZidellos = false;
    }
    int productid()
    {
        ifstream file;
        file.open("Product.txt", ios::ate);
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
            string pname, pas, sname, stc, pid, pri, byz, bno, date;
            int ID;
            file.seekg(0);
            while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
            {
                ID = stoi(pid);
            };
            file.close();
            return ID += 1;
        }
        file.close();
    }
    void CreatesellerAcc(int n, string shopname, string pass)
    {

        this->NumberOfProducts = n;
        this->shopname = shopname;
        this->pass = pass;
        int choice;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter product name : ";
            cin >> this->productName;
            cout << "Stock : ";
            cin >> this->stock;
            cout << "Enter price : ";
            cin >> this->price;
            cout << "Enter delivery option (press 1 for Deliver by zidello and 0 for Deliver by yourself): ";
            cin >> choice;
            while (choice != 1 && choice != 0)
            {
                cout << "Please enter a valid choice : ";
                cin >> choice;
            }
            if (choice == 1)
                this->ByZidellos = true;
            else
                this->ByZidellos = false;
            this->productID = productid();
            int choice;
            cout << "Press 1 for next and any other key for rewriting the information : ";
            cin >> choice;
            if (choice == 1)
                ProductWrite();
            else
                --i;
        }
    }
    void ProductWrite()
    {
        ofstream file;
        file.open("Product.txt", ios::app);
        file << this->productName << endl
             << this->pass << endl
             << this->stock << endl
             << this->price << endl
             << this->productID << endl
             << this->shopname << endl
             << this->ByZidellos << endl;
        file.close();
    }
};
class product : public SignInSeller //abstract class
{
public:
    void DisplayAllProducts()
    {
        ifstream file;
        file.open("Product.txt", ::ios::ate);
        file.seekg(0);
        string pname, pas, sname, stc, pid, pri, byz;
        int BYZ;
        cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
        {
            cout << setw(15) << pname << setw(15) << stc << setw(15)
                 << pri << setw(15) << pid << setw(15) << setw(15) << sname ;
                 BYZ=stoi(byz);
                 if(BYZ==1)
                 cout<< setw(15) << "By us" << endl;
                 else{
                     cout<< setw(15) << "By Seller" << endl;
                 }
        }
        file.close();
    }
    void SearchProducts(int id)
    {
        ifstream file;
        file.open("Product.txt", ::ios::ate);
        file.seekg(0);
        string pname, pas, sname, stc, pid, pri, byz;
        int ID,BYZ;
        cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
        {
            ID = stoi(pid);
            if (ID == id)

                cout << setw(15) << pname << setw(15) << stc << setw(15)
                     << pri << setw(15) << pid << setw(15) << setw(15) << sname ;
                 BYZ=stoi(byz);
                 if(BYZ==1)
                 cout<< setw(15) << "By us" << endl;
                 else{
                     cout<< setw(15) << "By Seller" << endl;
                 }
        }
        file.close();
    }
    void SearchProducts(string name)
    {

        ifstream file;
        file.open("Product.txt", ::ios::ate);
        file.seekg(0);
        string pname, pas, sname, stc, pid, pri, byz;
        int BYZ;
        cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
        {

            if (pname == name || sname == name)

                cout << setw(15) << pname << setw(15) << stc << setw(15)
                     << pri << setw(15) << pid << setw(15) << setw(15) << sname ;
                 BYZ=stoi(byz);
                 if(BYZ==1)
                 cout<< setw(15) << "By us" << endl;
                 else{
                     cout<< setw(15) << "By Seller" << endl;
                 }
        }
        file.close();
    }

    void SearchProducts(bool ByZID)
    {
        ifstream file;
        file.open("Product.txt", ::ios::ate);
        file.seekg(0);
        int BYZ;
        string pname, pas, sname, stc, pid, pri, byz;
        bool byzid;
        cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
        {
            byzid = stoi(byz);
            if (ByZID == byzid)

                cout << setw(15) << pname << setw(15) << stc << setw(15)
                     << pri << setw(15) << pid << setw(15) << setw(15) << sname;
                 BYZ=stoi(byz);
                 if(BYZ==1)
                 cout<< setw(15) << "By us" << endl;
                 else{
                     cout<< setw(15) << "By Seller" << endl;
                 }
        }
        file.close();
    }
};

class sellorattribute : public product //abstract class
{
public:
    void addproducts(string shopname, string pass)
    {
        ofstream file;
        file.open("Product.txt", ios::app);

        {
            this->pass = pass;
            this->shopname = shopname;
            cout << "Enter number of entries : ";
            int n;
            cin >> n;
            int choice;
            for (int i = 0; i < n; i++)
            {
                this->pass = pass;
                this->shopname = shopname;
                cout << "Enter product name : ";
                cin >> this->productName;
                cout << "Stock : ";
                cin >> this->stock;
                cout << "Enter price : ";
                cin >> this->price;
                cout << "Enter delivery option (press 1 for Deliver by zidello and 0 for Deliver by yourself): ";
                cin >> choice;
                if (choice == 1)
                    this->ByZidellos = true;
                else
                    this->ByZidellos = false;
                this->productID = productid();
                int choice;
                cout << "Press 1 for next and any other key for rewriting the information : ";
                cin >> choice;
                if (choice == 1)
                    ProductWrite();
                else
                    --i;
            }
        }
    }
    void editProduct(string shopname, string pass)
    {

        {
            int id;
            string pname, pas, sname, stc, pid, pri, byz;
            this->SearchProducts(shopname);
            cout << "Enter product id to edit : ";
            cin >> id;
            ifstream file;
            file.open("Product.txt");
            file.seekg(0);
            fstream temp;
            int PID;
            temp.open("temp.txt", ios::out);
            while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
            {
                PID = stoi(pid);
                if (PID == id)
                {
                    cout << "Enter product name to be update : ";
                    cin >> pname;
                    cout << "Enter stock : ";
                    cin >> stc;
                    cout << "Enter price : ";
                    cin >> pri;
                }

                temp << pname << endl
                     << pas << endl
                     << stc << endl
                     << pri << endl
                     << pid << endl
                     << sname << endl
                     << byz << endl;
            }
            file.close();
            temp.close();

            if (remove("Product.txt") != 0)
                cout << "error in deleting file" << endl;

            if (rename("temp.txt", "Product.txt") != 0)
                perror("Error moving file");
        }
    }
    void deleteproduct(string shopname, string pass)
    {
        // if (pass == this->pass && this->shopname == shopname)
        {
            int id;
            string pname, pas, sname, stc, pid, pri, byz;
            this->SearchProducts(shopname);
            cout << "Enter product id to edit : ";
            cin >> id;
            ifstream file;
            file.open("Product.txt");
            file.seekg(0);
            fstream temp;
            int PID;
            temp.open("temp.txt", ios::out);
            while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
            {
                PID = stoi(pid);
                if (PID != id)
                {
                    temp << pname << endl
                         << pas << endl
                         << stc << endl
                         << pri << endl
                         << pid << endl
                         << sname << endl
                         << byz << endl;
                }
            }
            file.close();
            temp.close();

            if (remove("Product.txt") != 0)
                cout << "error in deleting file" << endl;

            if (rename("temp.txt", "Product.txt") != 0)
                perror("Error moving file");
        }
    }
};
class Admin : public SignInFile
{

public:
    bool ShowSignINDetails(string Email, string Pass)
    {
        if (this->login(Email, Pass) == true)
            return true;
        else
            return false;
    }
    void Info(string cnic)
    {
        ifstream file;
        file.open("LoginInfo.txt", ::ios::ate);
        file.seekg(0);
        while (getline(file, this->email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            if (this->nic == cnic)
            {
                cout << "Email : " << this->email << endl
                     << "Mobile number : " << this->Number << endl
                     << "Address : " << this->address << endl
                     << "NIC : " << this->nic <<endl <<endl;
            }
        }
        file.close();
    }
    void Info()
    {
        ifstream file;
        file.open("LoginInfo.txt", ::ios::ate);
        file.seekg(0);
        while (getline(file, this->email) && getline(file, this->pass) && getline(file, this->Number) && getline(file, this->address) && getline(file, this->nic))
        {
            cout << "Email : " << this->email << endl
                 << "Mobile number : " << this->Number << endl
                 << "Address : " << this->address << endl
                 << "NIC : " << this->nic << endl<<endl;
        }
        file.close();
    }
    void showbills()
    {
        ifstream file;
        file.open("bills.txt", ::ios::ate);
        file.seekg(0);
        string pname, pas, sname, stc, pid, pri, byz, bno, date;
        int BYZ;
        //  getline(file, productName) && getline(file, pass) && file >> stock &&file >> price &&file >> productID &&file >> shopname &&file >> ByZidellos;
        cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << setw(15) << setw(15) << setw(15) << "Bill no" << setw(15) << "date" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz) && getline(file, bno) && getline(file, date))
        {
            //cout << "in whille" << endl;

            cout << setw(15) << pname << setw(15) << stc << setw(15)
                 << pri << setw(15) << pid << setw(15) << setw(15) << sname ;
                 BYZ=stoi(byz);
                 if(BYZ==1 || byz=="1")
                 cout<< setw(15) << "By us" ;
                 else{
                     cout<< setw(15) << "By Seller" ;
                 } cout<< setw(15) << bno << setw(15) << date << endl;

            // getline(file, productName) && getline(file, pass) && file >> stock &&file >> price &&file >> productID &&file >> shopname &&file >> ByZidellos;
        }
        file.close();
    }
};
static int BILLID;
class sellor : public sellorattribute
{
public:
    sellor()
    {
        cout << "Welcome to ZIDELLO's" << endl;
    }
    bool login(string shopname, string pass)
    {
        ifstream file;
        file.open("Product.txt", ios::ate);
        file.seekg(0);
        while (getline(file, this->productName) && file >> this->pass && file >> this->stock && file >> this->price && file >> this->productID && file >> this->shopname && file >> this->ByZidellos)
        {
            if (this->shopname == shopname && this->pass == pass)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    bool ShowSignINDetails(string Email, string Pass)
    {
        if (this->login(Email, Pass) == true)
            return true;
        else
            return false;
    }
};
class buyer : public product
{
    time_t now = time(0);
    // convert now to string form
    string dt = ctime(&now);
    int billno;

public:
    buyer()
    {
        
    }
    bool ShowSignINDetails(string Email, string Pass)
    {
        if (this->login(Email, Pass) == true)
            return true;
        else
            return false;
    }
    int billid()
    {
        ifstream file;
        file.open("bills.txt", ios::ate);
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
            while (getline(file, this->productName) && file >> this->pass && file >> this->stock && file >> this->price && file >> this->productID && file >> this->shopname && file >> this->ByZidellos && file >> this->billno && file >> this->dt && file >> this->address && file >> this->Number)
                ;
            file.close();
            return this->billno + 1;
        }
        file.close();
    }
    void buy()
    {BILLID=this->billid();
        {this->billno=BILLID;
        buy:
            bool check = false;
            int id;
            this->DisplayAllProducts();
            cout << endl
                 << "Enter id you want to buy" << endl;
            cin >> id;
            this->whattobuy(id);
        again:
            int choose;
            cout << "Press 1 to buy again \nPress 2 to to check out" << endl;
            cin >> choose;
            switch (choose)
            {
            case 1:
                goto buy;
                break;
            case 2:
                generatebill(this->billno);
                break;
            default:
                try
                {
                    if (choose != 1 || choose != 2)
                        throw 1;
                }
                catch (int)
                {
                    cout << "Enter valid input" << endl;
                    goto again;
                }
            }
        }
    }
    void whattobuy(int id)
    {
        ifstream file;
        file.open("Product.txt", ::ios::ate);
        file.seekg(0);
        fstream temp;
        string pname, pas, sname, stc, pid, pri, byz;
        temp.open("temp.txt", ios::out);
        int PID, STC;
        // cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz))
        {

            //cout << setw(15) << pname << setw(15) << stc << setw(15)
            // << pri << setw(15) << pid << setw(15) << setw(15) << sname << setw(15) << byz << endl;

            PID = stoi(pid);
            if (PID == id)
            {
                STC = stoi(stc);
                STC -= 1;
                ofstream file;
                file.open("bills.txt", ios::app);
                file << pname << endl
                     << pas << endl
                     << stc << endl
                     << pri << endl
                     << pid << endl
                     << sname << endl
                     << byz << endl
                     << this->billno << endl
                     << this->dt << endl;

                file.close();
            }
            temp << pname << endl
                 << pas << endl
                 << STC << endl
                 << pri << endl
                 << pid << endl
                 << sname << endl
                 << byz << endl;
        }
        temp.close();
        file.close();
        if (remove("Product.txt") != 0)
            cout << "error in deleting file" << endl;

        if (rename("temp.txt", "Product.txt") != 0)
            perror("Error moving file");
    }

    void generatebill(int id)
    {
        double total = 0;
        ifstream file;
        string pname, pas, sname, stc, pid, pri, byz,bno,date;
        file.open("bills.txt", ios::ate);
        file.seekg(0);
        cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << setw(15) << "Bill no" << setw(15) << "Date" << endl;
        int PID;
        double price;
        // cout << setw(15) << "Product name" << setw(15) << "Stock" << setw(15) << "Price" << setw(15) << "Product ID" << setw(15) << "Shop" << setw(15) << "By Zidello's" << endl;
        while (getline(file, pname) && getline(file, pas) && getline(file, stc) && getline(file, pri) && getline(file, pid) && getline(file, sname) && getline(file, byz)&&getline(file, bno)&&getline(file, date))
        {
            PID = stoi(bno);
            if (PID == id)
            {
                cout << setw(15) << pname << setw(15) << stc << setw(15)
                     << pri << setw(15) << pid << setw(15) << setw(15) << sname ;
                 
                 if(byz=="1")
                 cout<< setw(15) << "By us";
                 else{
                     cout<< setw(15) << "By Seller" ;
                 }
                 cout<<setw(15)<<bno<<setw(15)<<date<<endl;
                price=stod(pri);
                total+=price;
            }
        }
        cout << "Your total price is : " << total << endl;
    }
};
int main()
{
    // Admin a;
    // a.CreateAcc("sharjeel@yahoo.com", "Poorpie", "03354017997", "Scheme 33", "4220159066995");
    // a.ShowSignINDetails("sharjeel@yahoo.com", "Poorpie");
    int choose;
    cout << "Press 1 for admin\nPress 2 for sellor\npress 3 for buyers" << endl
         << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
    {string username,pass;
    cout<<"Enter user name : ";

    cin>>username;
    cout<<"Enter password : ";
cin>>pass;
if(username=="admin",pass=="admin123")
        {
        Admin *admin = new Admin;
        int choose;
        cout << "Press 1 for cnic searh in data\npress 2 for view all user data\npress 3 for view all bills" << endl;
        cin >> choose;
        if (choose == 1)
        {
            string cnic;
            cout << "Enter cnic you want to search : ";
            cin >> cnic;
            admin->Info(cnic);
        }
        else if (choose == 2)
        {
            admin->Info();
        }
        else if (choose == 3)
        {
            admin->showbills();
        }}
        else
        cout<<"Incorrect username/password"<<endl;
    }

    break;
    case 2:
    {
        sellor *S = new sellor;
        cout << "Press 1 for signup\npress 2 for login " << endl;
        int chose, n;
        string shopname, pass, email;
        cin >> chose;
        if (chose == 1)
        {
            string number, address, nic;
            cout << "Enter email address : ";
            cin >> email;
            cout << "Enter password : ";
            cin >> pass;
            cout << "Enter number : ";
            cin >> number;
            cout << "Enter address : ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter NIC : ";
            cin >> nic;
            cout << "Enter shop name : ";
            cin >> shopname;
            cout << "Enter number of type of product you want to sell : ";
            cin >> n;
            S->CreateAcc(email, pass, number, address, nic);
            S->CreatesellerAcc(n, shopname, pass);
        }
        else
        {
            cout << "Enter shop name : ";
            cin >> shopname;
            cout << "Enter password : ";
            cin >> pass;
            if (S->login(shopname, pass))
            {
            AGAIN:
                int chose;
                cout << "Press 1 for add products \nPress 2 for delete product\nPress 3 for edit product" << endl;
                cin >> chose;
                if (chose == 1)
                    S->addproducts(shopname, pass);
                else if (chose == 2)
                    S->deleteproduct(shopname, pass);
                else if (chose == 3)
                    S->editProduct(shopname, pass);
                else
                {
                    cout << "Please select right option" << endl;
                    goto AGAIN;
                }
            }
        }
        break;
    }
    case 3:

    {
        buyer *B = new buyer;
        cout << "Press 1 for signup\npress 2 for login " << endl;
        int chose;
        string email, pass;
        cin >> chose;
        if (chose == 1)
        {
            string number, address, nic;
            cout << "Enter email address : ";
            cin >> email;
            cout << "Enter password : ";
            cin >> pass;
            cout << "Enter number : ";
            cin >> number;
            cout << "Enter address : ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter NIC : ";
            cin >> nic;
            B->CreateAcc(email, pass, number, address, nic);
            B->buy();
        }
        else
        {
        again:
            cout << "Enter email : ";
            cin >> email;
            cout << "Enter password : ";
            cin >> pass;
            if (B->login(email, pass))
            {
                int choose;
                cout<<"Press 1 to searah product by product name/shop name\npress 2 to view all products\npress 3 to view products delivered by us\npress 4 to view product deliver by seller\npress 5 to buy"<<endl;
                cin>>choose;
                if(choose==1)
                {
                    string name;
                    cout<<"Enter shop/product name : ";
                    cin>>name;
                    B->SearchProducts(name);
                }
                else if(choose==2)
                {
                    B->DisplayAllProducts();
                }
                else if(choose==3)
                {
                    B->SearchProducts(1);
                }
                else if(choose==4)
                {
                    B->SearchProducts(0);
                }
                else if(choose ==5)
                {
                B->buy();

                }
            }
            else
            {
                cout << "Enter valid email/password" << endl;
                goto again;
            }
        }
        break;
    }
    default:
        break;
    }
}
