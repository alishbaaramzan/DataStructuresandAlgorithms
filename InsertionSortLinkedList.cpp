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
        Node* insertsort(Node* sorted, Node* ptr){
            if (sorted == NULL || ptr->data <= sorted->data) {
                ptr->next = sorted;
                sorted = ptr;
                return sorted;
            }

            Node* prev = NULL;
            Node* headref = sorted;
            while(headref!=NULL){
                if(headref->data > ptr->data){
                    break;
                }
                prev = headref;
                headref = headref->next;

            }
            ptr->next = headref;
            prev->next = ptr;
            return sorted;
        }
        void insertionSort(){
            Node* sorted = NULL;
            Node* ptr = head;

            while(ptr!=NULL){
                Node* next = ptr->next;
                sorted = insertsort(sorted, ptr);
                ptr = next;
            }
            head = sorted;
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

    linkedlist->insertionSort();

    linkedlist->display();

    delete linkedlist;
    return 0;
}
