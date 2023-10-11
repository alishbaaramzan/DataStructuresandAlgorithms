#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

class DoublyLinkedList{
    public:
        Node* head;
        Node* tail;

        DoublyLinkedList(){
            head = new Node();
            head->next = NULL;
            head->prev = NULL;
            tail = head;
        }

        void addNode(int val){
            Node* new_node = new Node();
            new_node->data = val;

            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = NULL;

            tail = new_node;
        }

        void display(){
            Node* ptr = head->next;

            if(ptr==NULL){
                cout << "Linked list is empty" << endl;
            }
            else{
                while(ptr!=NULL){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
                    cout << endl;
            }
    
        }

        bool isPalindrome(){
            Node* start = head->next;
            Node* end = tail;

            if(head==tail){
                cout << "Empty linked list" << endl;
                return false;
            }
            while(start!=end && start->next!=end){
                if(start->data!=end->data){
                    return false;
                }
                start = start->next;
                end = end->prev;
            }
            return true;
        }
};

int main(){
    DoublyLinkedList* dlinkedlist = new DoublyLinkedList();
    dlinkedlist->addNode(1);
    dlinkedlist->addNode(2);
    dlinkedlist->addNode(3);
    dlinkedlist->addNode(2);
    dlinkedlist->addNode(1);
    dlinkedlist->display();

    if(dlinkedlist->isPalindrome()){
        cout << "Linked list is palindrome" << endl;
    }
    else{
        cout << "Linked list is not palindrome" << endl;
    }
    return 0;
}