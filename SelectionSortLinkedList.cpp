#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }
        void insertAtEnd(int val){
            Node* new_node = new Node();
            new_node->data = val;
            new_node->next = NULL;

            if(head==NULL){
                head = new_node;
                return;
            }
            Node* ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        void display(){
            Node* ptr = head;
            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        void selectionSort(){
            Node* ptr = head;
            Node* ptr2 = NULL;
            Node* min_ptr = NULL;

            while(ptr->next!=NULL){
                min_ptr = ptr;
                ptr2 = ptr->next;
                while(ptr2 != NULL){
                    if(ptr2->data < min_ptr->data)
                        min_ptr = ptr2;
                    ptr2 = ptr2->next;
                }
                // swapping the value of the first node of the unsorted list and the minimum node
                if(min_ptr!=ptr){
                    int temp = min_ptr->data;
                    min_ptr->data = ptr->data;
                    ptr->data = temp;
                }
                ptr = ptr->next;
            }
        }
};
int main(){
    LinkedList* linkedlist = new LinkedList();
    linkedlist->insertAtEnd(6);
    linkedlist->insertAtEnd(7);
    linkedlist->insertAtEnd(1);
    linkedlist->insertAtEnd(15);
    linkedlist->insertAtEnd(10);

    linkedlist->display();

    linkedlist->selectionSort();

    linkedlist->display();

    delete linkedlist;
    return 0;
}