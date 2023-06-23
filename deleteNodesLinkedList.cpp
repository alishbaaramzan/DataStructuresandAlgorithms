#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node* deleteFirstNode(struct Node *head){
    struct Node *ptr = head->next;
    delete head;
    return ptr;
}

struct Node * deleteMiddleNode(struct Node *head, int index){
    struct Node *ptr = head;
    struct Node * nptr = head->next;
    for(int i = 0; i < index-1; i++){
        ptr = ptr->next;
        nptr = nptr->next;
    }
    ptr->next = nptr->next;
    delete nptr;
    return head;
}

struct Node * deleteEndNode(struct Node* head){
    struct Node *ptr = head;
    struct Node *nptr = head->next;
    while(nptr->next != NULL){
        ptr = ptr->next;
        nptr = nptr->next;
    }
    ptr->next = NULL;
    delete nptr;
    return head;
}

// delete node having a given value in data
struct Node* deleteNode(struct Node *head, int value){
    int index = 0;
    struct Node *ptr = head;
    struct Node *nptr = ptr;
    while(nptr->data != value){
        ptr = nptr;
        nptr = nptr->next;
        index++;
    }
    if(index==0){
        ptr = nptr->next;
    delete nptr;
    return ptr;
    }
    ptr->next = nptr->next;
    delete nptr;
    return head;
}
void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main(){
    struct Node *head = new Node();
    struct Node *second = new Node();
    struct Node *third = new Node();
    struct Node *tail = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = tail;

    tail->data = 4;
    tail->next = NULL;

    // traversal before deletion
    LinkedListTraversal(head);

    // deletion
    //head = deleteFirstNode(head);
    //head = deleteMiddleNode(head, 2);
    //head = deleteEndNode(head);
    head = deleteNode(head,4);

    // traversal after deletion
    LinkedListTraversal(head);
    return 0;

}