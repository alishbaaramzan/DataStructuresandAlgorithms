#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};
// Linked list traversal
void LinkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
        cout << ptr->data <<" ";
        ptr = ptr->next;
    }
}
int main(){
    struct Node * head = new Node();
    struct Node * second = new Node();
    struct Node * third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; // terminating at third

    LinkedListTraversal(head);
    return 0;
}