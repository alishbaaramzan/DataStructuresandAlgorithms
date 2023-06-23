#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// inserting a node at the start
struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *nptr = new Node();
    nptr->data = data;

    while(ptr->next!=head){
        ptr = ptr->next;
    }
    ptr->next = nptr;
    nptr->next = head;
    return nptr;
}

// insert a node at the middle
struct Node *insertAtMiddle(struct Node *head, int index, int data)
{
    struct Node *ptr = head;
    struct Node *nptr = new Node();

    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    nptr->next = ptr->next;
    nptr->data = data;
    ptr->next = nptr;
    return head;
}

// insert node at the end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *nptr = new Node();
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = nptr;
    nptr->next = head;
    nptr->data = data;
    return head;
}

// insert a node at a given address
struct Node* insertAtAddress(struct Node* head, struct Node* p, int data){
    struct Node *ptr = head;
    struct Node *nptr = new Node();
    while (ptr->next != p){
        ptr = ptr->next;
    }
     nptr->next = ptr->next;
     ptr->next = nptr;
     nptr->data = data;
     return head;
}
void traversal(struct Node *head){
    struct Node *ptr = head;

    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while(ptr!=head);

    cout << endl;
}
int main()
{
    struct Node *head = new Node();
    struct Node *second = new Node();
    struct Node *third = new Node();
    struct Node *fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth; 

    fourth->data = 4;
    fourth->next = head; // creating a circular connection

    traversal(head);

    //head = insertAtStart(head,0);
    //head = insertAtMiddle(head,2,0);
    //head = insertAtEnd(head,0);

    traversal(head);

    return 0;
}