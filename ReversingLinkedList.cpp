#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
};

class LinkedList{
    Node* head;
    public:
        LinkedList(){
            head = new Node();
            head = NULL;
        }
    void addNode(int value){
        Node* newNode = new Node();
        
        newNode->val = value;
        newNode->next = head;

        head = newNode;

    }
    void display(){
        Node* newNode = new Node();
        newNode = head;

        while(newNode!=NULL){
            cout << newNode->val << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }

    void reverseLinkedList(){
        Node* prev = new Node();
        Node* curr = new Node();
        Node* next = new Node();

        prev = NULL;
        curr = head;
        next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void reverseRecursion(){
        head = reverseLinkedListRecursion(head);
    }

    Node* reverseLinkedListRecursion(Node* head){

        // base condition
        if(head == NULL || head->next == NULL){
            return head;
        }

        // recursive call to reach the end of the linked list and start reversing the connections
        Node* new_head = reverseLinkedListRecursion(head->next);

        // reverse the connections
        head->next->next = head; 
        head->next  = NULL;

        return new_head;

    }
    ~LinkedList(){
        Node* curr = head;
        while(curr!=NULL){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }

    }
};
int main(){
    LinkedList* linkedlist = new LinkedList();
    linkedlist->addNode(1);
    linkedlist->addNode(2);
    linkedlist->addNode(3);
    linkedlist->addNode(4);
    linkedlist->addNode(5);
    
    linkedlist->display();

    linkedlist->reverseRecursion();

    linkedlist->display();

    delete linkedlist;
    return 0;
}