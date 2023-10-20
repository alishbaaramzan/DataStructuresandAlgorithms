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
        void bubbleSort(){
            Node* ptr = head;
            Node* start = head;
            Node* end = NULL;


            while(ptr->next!=NULL){
                start = head;
                while(start->next!=end){
                    if(start->data > start->next->data){
                        int temp = start->data;
                        start->data = start->next->data;
                        start->next->data = temp;
                    }
                    start = start->next;
                }
                end = start;
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

    linkedlist->bubbleSort();

    linkedlist->display();

    delete linkedlist;
    return 0;
}