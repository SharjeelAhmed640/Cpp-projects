#include <iostream>

#include <list>

using namespace std;

void display ( list <int>  &l )
{
    list<int>::iterator it;
    it = l.begin();
    // for (it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << "  ";
    // }
    // cout<<endl;
    
    
}
int main()
{

    // list<int> l1;

    // l1.push_back(5);
    // l1.push_back(15);
    // l1.push_back(9 + 3);
    // l1.sort();
    // display(l1);
    // // l1.remove(15);
    // // display(l1);


     list<int> l2;

    l2.push_back(10);
    l2.push_back(99);
    l2.push_back(30);
    l2.push_back(40);
    l2.push_back(50);
    //l2.sort();
    // l2.pop_back();
    // l2.pop_front();
    display(l2);


    // l2.merge(l1);
    //    display(l2);
    //    l2.reverse();
    //    display(l2);
    return 0;
}