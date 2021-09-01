#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
using namespace std;


class Node
{
    public:
    int data;
     Node *next;
     Node *prev;
     int size=0;

    void insert_front(struct Node **head, int new_data);
    void insert_After(struct Node *prev_node, int new_data);
    void insert_end(struct Node **head, int new_data);
    void displayList(struct Node *node);
    void displayspecific(struct Node *node, int n);
    void deleteNode(struct Node** head_ref, struct Node* del);
    void deleteNodeAtGivenPos(struct Node** head_ref, int n);
    Node *getNode(int data);
    void insertPos(Node **current, int pos, int data);
    void update(struct Node **head_ref, int n, int modified_val);
};

void Node::insert_front(struct Node **head, int new_data)
{
    //allocate memory for New node
    struct Node *newNode = new Node;

    //assign data to new node
    newNode->data = new_data;

    //new node is head and previous is null, since we are adding at the front
    newNode->next = (*head);
    newNode->prev = NULL;

    //previous of head is new node
    if ((*head) != NULL)
        (*head)->prev = newNode;

    this->size++;
    //head points to new node
    (*head) = newNode;
}
/* Given a node as prev_node, insert a new node after the given node */
void Node::insert_After(struct Node *prev_node, int new_data)
{
    //check if prev node is null
    try
    {
        if (prev_node == NULL)
        {

            throw 1;
        }
        //allocate memory for new node
        struct Node *newNode = new Node;

        //assign data to new node
        newNode->data = new_data;

        //set next of newnode to next of prev node
        newNode->next = prev_node->next;

        //set next of prev node to newnode
        prev_node->next = newNode;

        //now set prev of newnode to prev node
        newNode->prev = prev_node;

        //set prev of new node's next to newnode
        if (newNode->next != NULL)
            newNode->next->prev = newNode;
    }
    catch (int)
    {
        cout << "Previous node is required , it cannot be NULL";
    }
}

//insert a new node at the end of the list
void Node::insert_end(struct Node **head, int new_data)
{
    //allocate memory for node
    struct Node *newNode = new Node;

    struct Node *last = *head; //set last node value to head

    //set data for new node
    newNode->data = new_data;

    //new node is the last node , so set next of new node to null
    newNode->next = NULL;

    //check if list is empty, if yes make new node the head of list
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    //otherwise traverse the list to go to last node
    while (last->next != NULL)
        last = last->next;

    //set next of last to new node
    last->next = newNode;

    //set last to prev of new node
    newNode->prev = last;
    size++;
    return;
}

// This function prints contents of linked list starting from the given node
void Node::displayList(struct Node *node)
{
    struct Node *last;

    while (node != NULL)
    {
        cout << node->data << "<==>";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL"<<endl;
}

void Node::displayspecific(struct Node *node, int n)
{
    struct Node *last;
    list<int> l;
    while (node != NULL)
    {
        l.push_back(node->data);
        last = node;
        node = node->next;
    }
    list<int>::iterator it;
    it = l.begin();
    int count = 1;
    try
    {
        if (n <= size && n > 0)
            for (it = l.begin(); it != l.end(); it++)
            {
                if (count == n)
                    cout << *it << "  ";
                count++;
            }
        else
            throw 1;
        cout << endl;
    }
    catch (int)
    {
        cout << "Enter position is invalid " << endl;
    }
}
void Node::deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;
 
    /* Change next only if node to be deleted is NOT
       the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT
       the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
 size--;
    /* Finally, free the memory occupied by del*/
    free(del);
}
 
/* Function to delete the node at the given position
   in the doubly linked list */
void Node::deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0)
        return;
 
    struct Node* current = *head_ref;
    int i;
 
    /* traverse up to the node at position 'n' from
       the beginning */
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
 
    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return;
 
    /* delete the node pointed to by 'current' */
    deleteNode(head_ref, current);
}
Node* Node::getNode(int data)
{
    // allocating space
    Node *newNode = new Node();

    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a Node at required position
void Node::insertPos(Node **current, int pos, int data)
{

    // This condition to check whether the
    // position given is valid or not.
    try
    {
        if (pos < 1 || pos > size + 1)
            throw 1;
        else
        {

            // Keep looping until the pos is zero
            while (pos--)
            {

                if (pos == 0)
                {

                    // adding Node at required position
                    Node *temp = getNode(data);

                    // Making the new Node to point to
                    // the old Node at the same position
                    temp->next = *current;

                    // Changing the pointer of the Node previous
                    // to the old Node to point to the new Node
                    *current = temp;
                }
                else
                    // Assign double pointer variable to point to the
                    // pointer pointing to the address of next Node
                    current = &(*current)->next;
            }
            size++;
        }
    }
    catch (int)
    {
        cout << "Invalid position!" << endl;
    }
}
void Node::update(struct Node **head_ref, int n, int modified_val)
{
    deleteNodeAtGivenPos(head_ref, n);
    insertPos(head_ref, n, modified_val);
}

//main program
int main()
{
    /* Start with the empty list */
    class Node *head = NULL;

    // // Insert 40 as last node
    // insert_end(&head, 40);

    // // insert 20 at the head
    // insert_front(&head, 20);

    // // Insert 10 at the beginning.
    // insert_front(&head, 10);

    // // Insert 50 at the end.
    // insert_end(&head, 50);

    // // Insert 30, after 20.
    // insert_After(head->next, 30);

    // //deleteNodeAtGivenPos(&head, 3);
    // // insertPos(&head,4,99);
    // update(&head, 2, 99);
    // displayspecific(head, 10);

    // cout << "Doubly linked list is as follows: " << endl;
    // displayList(head);

    int choose=0, data, position;


    while (choose != 9)
    {
    cout <<endl << "Enter:" << endl
         << "1 for inserts node at the front of the list" << endl
         << "2 for insert a new node at the end of the list" << endl
         << "3 for insert a new node after the given node" << endl
         << "4 for insert a Node at required position" << endl
         << "5 for delete node at specific position" << endl
         << "6 for modify node at specific position" << endl
         << "7 for display dll" << endl
         << "8 for display specific node" << endl
         << "9 for end program" << endl
         << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Enter data value : ";
            cin >> data;
            head->insert_front(&head, data); // insert data at the head
            break;

        case 2:
            cout << "Enter data value : ";
            cin >> data;
            head->insert_end(&head, data); // Insert data as last node
            break;

        case 3:
            cout << "Enter data value : ";
            cin >> data;
            head->insert_After(head->next, data); // Insert data, after previous nodes data.
            break;

        case 4:
            cout << "Enter data value : ";
            cin >> data;
            cout << "Enter position : ";
            cin >> position;
            head->insertPos(&head, position, data); //insert data at nth position
            break;

        case 5:
            cout << "Enter position : ";
            cin >> position;
            head->deleteNodeAtGivenPos(&head, position); //deleting node at nth position
            break;

        case 6:
            cout << "Enter data value : ";
            cin >> data;
            cout << "Enter position : ";
            cin >> position;
            head->update(&head, position, data); //updating data of nth node

        case 7:
            cout << "Doubly linked list is as follows: " << endl;
            head->displayList(head); //display full dll
            break;

        case 8:
            cout << "Enter position : ";
            cin >> position;
            cout << "display data of " << position << " (th/rd/st/nd) position node only " << endl;
            head->displayspecific(head, position);

        case 9:
            break;

        default:
            cout << "you have entered invalind input" << endl
                 << endl;
            break;
        }
    }
    return 0;
}