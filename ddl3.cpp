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
template <class T = double>
class Point
{
    public:
    T x, y;
     Point  *next; // to point next point node
     Point  *prev; // to point previous point node
} ;

Point <double> *start; // globle pont node
/*
 Class Declaration 
 */
class double_llist  
{
public:
    void create_list(double valuex, double valuey);
    void add_begin(double valuex, double valuey);
    void add_after(double valuex, double valuey, double position);
    void delete_element(double valuex, double valuey);
    void edit_element(double valuex, double valuey);
    void search_element(double valuex, double valuey);
    void display_dlist();
    void displayspecific(double);
    void count();
    void reverse();
    double_llist()
    {
        start = NULL; //  initailly pointing to null
    }
};

void double_llist ::displayspecific(double n)
{// exception handle 
    try
    {
        struct Point <double> *q = start; //  creating new point list
        int  cnt = 0; // counter for counting all points
        while (q != NULL)
        {
            q = q->next; // every time q point to next node point 
            cnt++;
        }
        if (cnt < n) //if position is more than the no of element in list thorw exceptin
        {
            throw 1;
        }
        cnt = 1; // again starting from 1
        q = start;// q pointing to the head
        while (q != NULL)
        {
            q = q->next;
            cnt++;
            if (cnt == n) // if cnt equal to the desired position then print 
            {
                cout << "specific Point : ";
                cout << "(" << q->x << " , " << q->y << ")" << endl;
            }
        }
    }
    catch (double)
    {
        cout << "EXP: Invalid position " << endl;
    }
}
/*
 * Main: Conatins Menu
 */
int main()
{
    int choice;
    double  elementx, elementy, position;
    double_llist *dl = new double_llist(); //creaing dynamic list
    while (1) //infinte loop
    {
        cout << endl
             << "----------------------------" << endl;
        cout << endl
             << "Operations on Doubly linked list" << endl;
        cout << endl
             << "----------------------------" << endl;
        cout << "0.specific Point" << endl;
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
void double_llist::create_list(double valuex, double valuey)
{
    struct Point<double> *s, *temp; // create new point 
    temp = new  (class Point<double>);
    temp->x = valuex; // assigning value
    temp->y = valuey;
    temp->next = NULL;
    if (start == NULL) // if no point in head then assign it to head
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;// assigning in the last 
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

/*
 * Insertion at the beginning
 */
void double_llist::add_begin(double valuex, double valuey)
{
    try
    {
        if (start == NULL)//if head is null throw exception 
        {
            throw 1;
        }
        struct Point<double> *temp; //creating new point 
        temp = new (class Point<double>);
        temp->prev = NULL; // assiging null to previous node
        temp->x = valuex; // value assignent
        temp->y = valuey; // value assignent
        temp->next = start; // assingnig new point to head and head point to after head point and so on
        start->prev = temp;
        start = temp;
        cout << "Element Inserted" << endl;
    }
    catch (double)
    {
        cout << "First Create the list." << endl;
    }
}

/*
 * Insertion of element at a particular position
 */
void double_llist::add_after(double valuex, double valuey, double pos)
{
    try{if (start == NULL)// if head is null throw an exception 
    {
       
        throw 'c';
    }
    struct Point<double> *tmp, *q; // creating 2 new point nodes 
    int  i;
    q = start; // assigning start to q
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
        if (q == NULL)//if q becomes null and pos is not in the range(total no of elements) the throw an error
        {
            throw pos;
        }
    }
    tmp = new (class Point<double>);// get new point 
    tmp->x = valuex;
    tmp->y = valuey;
    if (q->next == NULL)//if next node is null then assign new node to nect node
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next; // assign mext node(point) of temp to next node(point) of q
        tmp->next->prev = tmp; //assign temp to tmp->next->prev
        q->next = tmp; // assign temp to next node(point) of q
        tmp->prev = q;// assign q to temp previous node(point)
    }
    cout << "Element Inserted" << endl;}
    catch(char)
    { cout << "EXP : First Create the list." << endl;}
    catch(double pos)
    {
cout << "There are less than ";
            cout << pos << " elements." << endl;
    }
}

/*
 * Deletion of element from the list
 */
void double_llist::delete_element(double valuex, double valuey)
{
    struct Point<double> *tmp, *q;
    /*first element deletion*/
    if (start->x == valuex && start->y == valuey)//if 1st element is desired elemt to delete 
    {
        tmp = start;//assign start to temp
        start = start->next;// asign start's next to start head
        start->prev = NULL;// asign start pre to null
        cout << "Element Deleted" << endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->x == valuex && q->next->y == valuey)//if point is in b/w to delete
        {
            tmp = q->next;// assign next of q to temp point node
            q->next = tmp->next; //assign temp's next to q's next
            tmp->next->prev = q; // assign q to tmp->next->prev
            cout << "Element Deleted" << endl;
            free(tmp); // free temp
            return;
        }
        q = q->next; //until the desired point is found 
    }
    /*last element deleted*/
    if (q->next->x == valuex && q->next->y == valuey)//if last point is the desired point to del
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout << "Element Deleted" << endl;
        return;
    }
    cout << "Element " << valuex << "," << valuey << " not found" << endl;
}
void double_llist::edit_element(double valuex, double valuey)
{
    struct Point<double> *tmp, *q;
    double cnt = 0, x, y;
    /*first element deletion*/
    if (start->x == valuex && start->y == valuey)
    {
        cnt = 1;
        tmp = start;
        start = start->next; // make 2nd point head del orignal head
        start->prev = NULL;
        //   cout<<"Element Deleted"<<endl;
        free(tmp);
        cout << "Enter x : "; // take new point
        cin >> x;
        cout << "Enter y : ";
        cin >> y;
        add_after(x, y, cnt); // note the matched position and add new point to that position
        return;
    }
    cnt = 0;
    q = start;
    while (q->next->next != NULL)
    {
        cnt++;
        /*Element deleted in between*/
        if (q->next->x == valuex && q->next->y == valuey)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            //  cout<<"Element Deleted"<<endl;
            free(tmp);
            cout << "Enter x : ";
            cin >> x;
            cout << "Enter y : ";
            cin >> y;
            add_after(x, y, cnt);
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
        //   cout<<"Element Deleted"<<endl;
        cin >> x;
        cout << "Enter y : ";
        cin >> y;
        add_after(x, y, cnt - 1);
        return;
    }
    cout << "Element " << valuex << "," << valuey << " not found" << endl;
}
/*
 * Display elements of Doubly Link List
 */
void double_llist::display_dlist()
{
    struct Point<double> *q;
    if (start == NULL)// if head is empty then list is empty
    {
        cout << "List empty,nothing to display" << endl;
        return;
    }
    q = start;
    cout << "The Doubly Link List is :" << endl;
    while (q != NULL) // transverse until null is found
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
    struct Point <double> *q = start;
    double cnt = 0;
    while (q != NULL)// transverse until null is found
    {
        q = q->next;
        cnt++;//counter
    }
    cout << "Number of elements are: " << cnt << endl;
}

/*
 * Reverse Doubly Link List
 */
void double_llist::reverse()
{
    struct Point<double> *p1, *p2;//new point nodes
    p1 = start;// p1 point to start
    p2 = p1->next;// p2 points to p1s next
    p1->next = NULL;// p1 next to null
    p1->prev = p2;// p1 prev to p2 head
    while (p2 != NULL)//while one if the list is not null
    {
        p2->prev = p2->next; 
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout << "List Reversed" << endl;
}