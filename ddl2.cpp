/*
 * C++ Program to Implement Doubly Linked List 
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
/*
 * Node Declaration
 */
using namespace std;
template <class T = int>
class Point
{
    public:
    T x, y;
     Point  *next;
     Point  *prev;
} ;

Point<int> *start;
/*
 Class Declaration 
 */
class double_llist
{
public:
    void create_list(int valuex, int valuey);
    void add_begin(int valuex, int valuey);
    void add_after(int valuex, int valuey, int position);
    void delete_element(int valuex, int valuey);
    void edit_element(int valuex, int valuey);
    void search_element(int valuex, int valuey);
    void display_dlist();
    void displayspecific(int);
    void count();
    void reverse();
    double_llist()
    {
        start = NULL;
    }
};

void double_llist ::displayspecific(int n)
{
    try
    {
        struct Point<int> *q = start;
        int cnt = 0;
        while (q != NULL)
        {
            q = q->next;
            cnt++;
        }
        if (cnt < n)
        {
            throw 1;
        }
        cnt = 1;
        q = start;
        while (q != NULL)
        {
            q = q->next;
            cnt++;
            if (cnt == n)
            {
                cout << "specific point : ";
                cout << "(" << q->x << " , " << q->y << ")" << endl;
            }
        }
    }
    catch (int)
    {
        cout << "EXP: Invalid position " << endl;
    }
}
/*
 * Main: Conatins Menu
 */
int main()
{
    int choice, elementx, elementy, position;
    double_llist *dl = new double_llist();
    while (1)
    {
        cout << endl
             << "----------------------------" << endl;
        cout << endl
             << "Operations on Doubly linked list" << endl;
        cout << endl
             << "----------------------------" << endl;
        cout << "0.specific point" << endl;
        cout << "1.Create Node" << endl;
        cout << "2.Add at begining" << endl;
        cout << "3.Add after position" << endl;
        cout << "4.Delete" << endl;
        cout << "5.Display" << endl;
        cout << "6.Modify" << endl;
        cout << "7.Reverse" << endl;
        cout << "8.Quit" << endl;
        cout << "9.count" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Enter position : ";
            cin >> position;
            dl->displayspecific(position);
            break;
        case 1:
            cout << "Enter the x coordinate : ";
            cin >> elementx;
            cout << "Enter the y coordinate : ";
            cin >> elementy;
            dl->create_list(elementx, elementy);
            cout << endl;
            break;
        case 2:
            cout << "Enter the x coordinate : ";
            cin >> elementx;
            cout << "Enter the y coordinate : ";
            cin >> elementy;
            dl->add_begin(elementx, elementy);
            cout << endl;
            break;
        case 3:
            cout << "Enter the x coordinate : ";
            cin >> elementx;
            cout << "Enter the y coordinate : ";
            cin >> elementy;
            cout << "Insert Element after postion: ";
            cin >> position;
            dl->add_after(elementx, elementy, position);
            cout << endl;
            break;
        case 4:
            if (start == NULL)
            {
                cout << "List empty,nothing to delete" << endl;
                break;
            }
            cout << "Enter the x coordinate : ";
            cin >> elementx;
            cout << "Enter the y coordinate : ";
            cin >> elementy;
            dl->delete_element(elementx, elementy);
            cout << endl;
            break;
        case 5:
            dl->display_dlist();
            cout << endl;
            break;
        case 6:
            cout << "Enter the x coordinate : ";
            cin >> elementx;
            cout << "Enter the y coordinate : ";
            cin >> elementy;
            dl->edit_element(elementx, elementy);
            break;
        case 7:
            if (start == NULL)
            {
                cout << "List empty,nothing to reverse" << endl;
                break;
            }
            dl->reverse();
            cout << endl;
            break;
        case 8:
            exit(1);
        case 9:
            dl->count();
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

/*
 * Create Double Link List
 */
void double_llist::create_list(int valuex, int valuey)
{
    struct Point<int> *s, *temp;
    temp = new  (class Point<int>);
    temp->x = valuex;
    temp->y = valuey;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

/*
 * Insertion at the beginning
 */
void double_llist::add_begin(int valuex, int valuey)
{
    try
    {
        if (start == NULL)
        {
            throw 1;
        }
        struct Point<int> *temp;
        temp = new (class Point<int>);
        temp->prev = NULL;
        temp->x = valuex;
        temp->y = valuey;
        temp->next = start;
        start->prev = temp;
        start = temp;
        cout << "Element Inserted" << endl;
    }
    catch (int)
    {
        cout << "First Create the list." << endl;
    }
}

/*
 * Insertion of element at a particular position
 */
void double_llist::add_after(int valuex, int valuey, int pos)
{
    try{if (start == NULL)
    {
       
        throw 'c';
    }
    struct Point<int> *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
        if (q == NULL)
        {
            throw pos;
        }
    }
    tmp = new (class Point<int>);
    tmp->x = valuex;
    tmp->y = valuey;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout << "Element Inserted" << endl;}
    catch(char)
    { cout << "EXP : First Create the list." << endl;}
    catch(int pos)
    {
cout << "There are less than ";
            cout << pos << " elements." << endl;
    }
}

/*
 * Deletion of element from the list
 */
void double_llist::delete_element(int valuex, int valuey)
{
    struct Point<int> *tmp, *q;
    /*first element deletion*/
    if (start->x == valuex && start->y == valuey)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout << "Element Deleted" << endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->x == valuex && q->next->y == valuey)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout << "Element Deleted" << endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    /*last element deleted*/
    if (q->next->x == valuex && q->next->y == valuey)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout << "Element Deleted" << endl;
        return;
    }
    cout << "Element " << valuex << "," << valuey << " not found" << endl;
}
void double_llist::edit_element(int valuex, int valuey)
{
    bool check=false;
    int count = 0;
    int x,y;
     Point<int> *temp;
    temp = start;
    while (temp != NULL) // Start traversing from head node
    {
        if (temp->x == valuex && temp->y == valuey)
        { check=true;
            cout<<"Enter x : ";
            cin>>x;

            cout<<"Enter y : ";
            cin>>y;
            temp->x = x; // change the element in the list
            temp->y=y;
        }
        else
        {
            count = count + 1;
            temp = temp->next;
        }
    }
    if(check==false)
    cout<<"Point not found"<<endl;
}
/*
 * Display elements of Doubly Link List
 */
void double_llist::display_dlist()
{
    struct Point<int> *q;
    if (start == NULL)
    {
        cout << "List empty,nothing to display" << endl;
        return;
    }
    q = start;
    cout << "The Doubly Link List is :" << endl;
    while (q != NULL)
    {
        cout << q->x << "," << q->y << " <-> ";
        q = q->next;
    }
    cout << "NULL" << endl;
}

/*
 * Number of elements in Doubly Link List
 */
void double_llist::count()
{
    struct Point <int> *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout << "Number of elements are: " << cnt << endl;
}

/*
 * Reverse Doubly Link List
 */
void double_llist::reverse()
{
    struct Point<int> *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout << "List Reversed" << endl;
}