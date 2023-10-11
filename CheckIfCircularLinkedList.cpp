#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
class CircularLinkedList{
    Node* head;
    public:
        CircularLinkedList(){
            head = NULL;
        }
        void addNode(int data){
            Node* ptr = new Node();
            ptr->data = data;
            ptr->next = head;

            head = ptr;
        }
        void display(){
            Node* ptr = head;
            if(head!=NULL){
            do{
                cout << ptr->data << " ";
                ptr = ptr->next;
            }while(ptr!=head);
            }
        }
        void makeCircular(){
            Node* ptr = head;

            while(ptr->next!=NULL){
                ptr = ptr->next;
            }

            ptr->next = head;
        }
        bool isCircular(){
            Node* ptr = head->next;

            while(ptr!=NULL && ptr!=head){
                ptr = ptr->next;
            }

            if(ptr==NULL) return false;
            else if(ptr==head) return true;
        }
        
        bool isCircularRecursion(){
            return isCircularRecursionImplementation(head->next);
        }

        bool isCircularRecursionImplementation(Node* nhead){
            if(nhead==NULL) return false;
            if(nhead==head) return true;

            return isCircularRecursionImplementation(nhead->next);
        }

        int countNodes(){
            Node* ptr = head->next;
            int count;
            if(head==NULL) count = 0;
            else count = 1;

            while(ptr!=head){
                count++;
                ptr = ptr->next;
            }
            return count;
        }
        // function to swap first and last node of a linked list
        void swapFirstandLast(){
            Node*ptr = head;
            Node*prev = NULL;

            if(ptr!=NULL || ptr->next!=NULL){
            while(ptr->next!=head){
                prev = ptr;
                ptr = ptr->next;
            }
            ptr->next = head->next;
            head->next = ptr;
            prev->next = head;
            head = ptr;
            }
        }
        ~CircularLinkedList(){
            Node* ptr = head;
            while(ptr!=NULL){
                Node*next = ptr->next;
                delete ptr;
                ptr = next;
            }
        }
};
int main(){
    CircularLinkedList* clinkedlist = new CircularLinkedList();
    clinkedlist->addNode(1);
    clinkedlist->addNode(2);
    clinkedlist->addNode(3);
    clinkedlist->addNode(4);
    clinkedlist->addNode(5);

    clinkedlist->makeCircular();

    bool check = clinkedlist->isCircularRecursion();

    if(check){
        cout << "Linked List is Circular" << endl;
        cout << "Number of nodes is " << clinkedlist->countNodes() << endl;
    }
    else
        cout << "Linked List is not Circular" << endl;
    
    cout << "Circular linked list before swapping the first and last node: " << endl;
    clinkedlist->display();

    cout << endl;
    cout << "circular linked list after swapping the first and last node: " << endl;
    clinkedlist->swapFirstandLast();
    clinkedlist->display();

    delete clinkedlist;
    return 0;
    
    /*
    Time Complexity = O(N)
    */
}