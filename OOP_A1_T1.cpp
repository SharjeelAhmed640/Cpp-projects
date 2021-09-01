#include <iostream>

#include <string>

#include <cstring>

#include <cmath>

using namespace std;

template <class T>

class bank_det
{

    string name, nic, Address, contact;

    T open_bal, current_bal;

    int pin, age;

public:
    bank_det(int &PIN = 0)
    {

        this->pin = PIN;
    }

    ~bank_det()
    {

        cout << endl
             << "Thank you" << endl;
    }

    void setData(string &NAME, string &NIC, string &ADDRESS, string &CONTACT, T O_bal, T C_bal, int AGE)

    {

        this->name = NAME;

        this->nic = NIC;

        this->Address = ADDRESS;

        this->contact = CONTACT;

        this->open_bal = O_bal;

        this->current_bal = C_bal;

        this->age = AGE;
    }

    void check_bal(int &code)

    {

        if (code == this->pin)

        {

            if (age >= 60)

            {

                cout << endl
                     << "Tax : 0.15%" << endl;

                current_bal = (current_bal) - (current_bal * 0.15);
            }

            else
            {

                cout << endl
                     << "Tax : 0.25%" << endl;

                current_bal = (current_bal) - (current_bal * 0.25);
            }

            cout << endl
                 << "Current Balance : " << current_bal << endl

                 << "Opening Balance : " << open_bal << endl

                 << "Name : " << name << endl

                 << "Age : " << age << endl;
        }
    }
};

int main()
{

    string name, nic, address, contact;

    int pin, age;

    float open_bal, cur_bal;

    cout << "Enter your name : ";

    getline(cin, name);

    cout << "Enter your age : ";

    cin >> age;

    cout << "Enter your NIC : ";

    cin >> nic;

    cout << "Enter your address : ";

    cin.ignore();

    getline(cin, address);

    cout << "Enter your contact : ";

    cin >> contact;

    cout << "Enter your pin : ";

    cin >> pin;

    cout << "Enter your opening Balance : ";

    cin >> open_bal;

    cout << "Enter your current Balance : ";

    cin >> cur_bal;

    bank_det<float> Data1(pin);

    Data1.setData(name, nic, address, contact, open_bal, cur_bal, age);

    cout << endl
         << endl
         << "Enter your pin to view Balance : ";

    cin >> pin;

    Data1.check_bal(pin);

    return 0;
}