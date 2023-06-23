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
    struct Node *ptr = new Node();
    ptr->next = head;
    ptr->data = data;
    return ptr;
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
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = nptr;
    nptr->next = NULL;
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
// Linked list traversal
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    struct Node *head = new Node();
    struct Node *second = new Node();
    struct Node *third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; // terminating at third

    // traversal before insertion
    LinkedListTraversal(head);

    // insertion
    // head = insertAtStart(head,0);
    //head = insertAtMiddle(head, 2, 6);
    //head = insertAtEnd(head,44);
    head = insertAtAddress(head,second,33);
    
    // traversal after insertion
    LinkedListTraversal(head);

    return 0;
}