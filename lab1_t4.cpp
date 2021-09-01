/*Task - 04:
Define a struct, menuItemType, with two components: menuItem of type string and menuPrice of
type double. Write a program to help a local restaurant automate its breakfast billing system. The
program should do the following:
A. Show the customer the different breakfast items offered by the restaurant.
B. Allow the customer to select more than one item from the menu.
C. Calculate and print the bill.
Assume that the restaurant offers the following breakfast items (the price of each item is shown to
the right of the item):
Plain Egg $1.45
Bacon and Egg $2.45
Muffin $0.99
French Toast $1.99
Fruit Basket $2.49
Cereal $0.69
Coffee $0.50
Tea $0.75
Use an array, menuList, of the struct menuItemType.*/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
struct menuItemType
{
    string menuItem;
    double menuPrice;
};

int main()
{

    cout << "***** MENU *****" << endl;
    cout
        << setw(50) << left << "press 1 Plain Egg      $1.45" << endl
        << setw(50) << left << "press 2 Bacon and Egg  $2.45" << endl
        << setw(50) << left << "press 3 Muffin         $0.99" << endl
        << setw(50) << left << "press 4 French Toast   $1.99" << endl
        << setw(50) << left << "press 5 Fruit Basket   $2.49" << endl
        << setw(50) << left << "press 6 Cereal         $0.69" << endl
        << setw(50) << left << "press 7 Coffee         $0.50" << endl
        << setw(50) << left << "press 8 Tea            $0.75" << endl;
    int select, count;
    double bill = 0;
    cout << "\nHow many items do you want to buy : ";
    cin >> count;
    menuItemType *item = new menuItemType[select];
    for (int i = 0; i < count; i++)
    {
        cout << "select item no : " << i + 1 << "  ";
        cin >> select;
        if (select == 1)
        {
            item[i].menuItem = "Plain Egg";
            item[i].menuPrice = 1.45;
        }
        else if (select == 2)
        {
            item[i].menuItem = "Bacon and Egg";
            item[i].menuPrice = 2.45;
        }
        else if (select == 3)
        {
            item[i].menuItem = "Muffin";
            item[i].menuPrice = 0.99;
        }
        else if (select == 4)
        {
            item[i].menuItem = "French Toast";
            item[i].menuPrice = 1.99;
        }
        else if (select == 5)
        {
            item[i].menuItem = "Fruit Basket";
            item[i].menuPrice = 2.49;
        }
        else if (select == 6)
        {
            item[i].menuItem = "Cereal";
            item[i].menuPrice = 0.69;
        }
        else if (select == 7)
        {
            item[i].menuItem = "Coffe";
            item[i].menuPrice = 0.50;
        }
        else if (select == 8)
        {
            item[i].menuItem = "Tea";
            item[i].menuPrice = 0.75;
        }
        bill += item[i].menuPrice;
    }
    cout << endl
         << endl
         << "*****ITEMS BOUGHT*****" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << setw(20) << left << item[i].menuItem << item[i].menuPrice << endl;
    }
    cout << endl
         << "Total Bill : " << bill;

    return 0;
}