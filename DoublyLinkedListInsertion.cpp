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
            tail = head; // initially tail and head are the same because we have not yet added any node
            
        }

        void display(){
            Node* ptr = head->next;

            if(ptr==NULL){
                cout << "Empty linked list" << endl;
            }
            else{
                while(ptr!=NULL){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
                cout << endl;
            }
        }

        void addNodeatStart(int val){
            Node* new_node = new Node();
            new_node->data = val;

            if(head==tail){
                // adjusting the next and previous links for the new node
                new_node->next = head->next;
                head->next = new_node;
                new_node->prev = head;
                tail = new_node;
            }
            else{
                new_node->next = head->next;
                new_node->prev = head;

                (head->next)->prev = new_node;
                head->next = new_node;
            }
            // Time Complexity = O(1)
        }

        void addNodeAtEnd(int val){
            Node* new_node = new Node();
            new_node->data = val;

            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = NULL;

            tail = new_node;

            // Time Complexity = O(1)
        }

        void addNodeAfterValue(int val){
            Node* ptr = head->next;
            Node* new_node = new Node();
            new_node->data = 0; // arbitrary value
            
           while(ptr!=NULL){
            if(ptr->data == val) break;
            ptr = ptr->next;
           }

            if(ptr==tail){
                tail = new_node;
            }
            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next = new_node;

            // Time Complexity = O(N)
        }

        void addNodeBeforeValue(int val){
            Node* ptr = head->next;
            Node* new_node = new Node();
            new_node->data = 0; // arbitrary value

            while(ptr!=NULL){
                if(ptr->data == val){
                    break;
                }
                ptr = ptr->next;
            }

            new_node->next = (ptr->prev)->next;
            new_node->prev = ptr->prev;

            (ptr->prev)->next = new_node;
            ptr->prev = new_node;

            // Time Complexity = O(N)
        }
};

int main(){
    DoublyLinkedList* dlinkedlist = new DoublyLinkedList();

    // Test cases for inserting node at the start
        // dlinkedlist->addNodeatStart(1);
        // dlinkedlist->addNodeatStart(2);
        // dlinkedlist->addNodeatStart(3);
        // dlinkedlist->display();
        // cout << dlinkedlist->tail->data << endl;

    // Test cases for inserting node at the end
        dlinkedlist->addNodeAtEnd(1);
        dlinkedlist->addNodeAtEnd(2);
        dlinkedlist->addNodeAtEnd(3);
        dlinkedlist->display();
        cout << "Tail: " << dlinkedlist->tail->data << endl;
    
    // Test cases for inserting node after a value that exists in the linked list
    //     dlinkedlist->addNodeAfterValue(1);
    //     dlinkedlist->display();
    //     cout << "Tail: " << dlinkedlist->tail->data << endl;
    //     dlinkedlist->addNodeAfterValue(3);
    //     dlinkedlist->display();
    //     cout << "Tail: " << dlinkedlist->tail->data << endl;

    // Test cases for inserting node before a value which exists in the linked list
        dlinkedlist->addNodeBeforeValue(1);
        dlinkedlist->display();
        cout << "Tail: " << dlinkedlist->tail->data << endl;
        dlinkedlist->addNodeBeforeValue(3);
        dlinkedlist->display();
        cout << "Tail: " << dlinkedlist->tail->data << endl;
        dlinkedlist->addNodeBeforeValue(2);
        dlinkedlist->display();
        cout << "Tail: " << dlinkedlist->tail->data << endl;
    

    delete dlinkedlist;
    return 0;

}