#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    Node* head;
    public:
        // initializing the head to zero
        LinkedList(){
            head = NULL;
        }
        // function to display the list
        void display(){
            Node* ptr = head;
            // checking if list is empty
            if(ptr==NULL){
                cout << "List is empty";
                return;
            }
            // iterating till we reach NULL and displaying all values
            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        // function to add a node to the end of the list
        void addback(int val){
            Node* new_node = new Node();
            new_node->data = val;
            Node* ptr = head;

            // checking if the list is empty
            if(ptr==NULL){
                new_node->next = ptr;
                head = new_node;
                cout << val << " added to the end of the list" << endl;
                return;
            }
            // traversing the list until we reach the last node
            while(ptr->next!=NULL){
                ptr = ptr-> next;
            }
            // after the last node we add another
            new_node->next = ptr->next;
            ptr->next = new_node;
            cout << val << " added to the end of list" << endl;
        }
        // function to return the pointer to the node containing the given data
        Node* find(int val){
            Node* ptr = head;

            // checking if the list is empty
            if(ptr==NULL){
                cout << "List is empty" << endl;
                return NULL;
            }
            // traversing to find the required node
            while(ptr!=NULL){
                if(ptr->data==val){
                    break;
                }
                ptr = ptr->next;           \
             }
             // returning the pointer(NULL if not found)
             return ptr;
        }
        // function to delete the node containing a given value
        void delnode(int val){
            Node* ptr = head;
            Node* prev = NULL;

            // checking if the list is empty
            if(ptr==NULL){
                cout << "List is empty" << endl;
                return;
            }
            // if the value lies at head node
            else if(head->data==val){
                Node* toDel = head;
                head = head->next;
                delete toDel;
            }
            else{
                // traversing to find the required node
                while(ptr!=NULL){
                    if(ptr->data==val){
                        break;
                    }
                    prev = ptr;
                    ptr = ptr->next;           \
                }
                // deleting the node pointed to by ptr
                prev->next=ptr->next;
                delete ptr;
            }
        }
        // function to delete the list at the end
        ~LinkedList(){
            Node* ptr = head;
            while(ptr!=NULL){
                Node*next = ptr->next;
                delete ptr;
                ptr = next;
            }
        }
};
int main(){
    LinkedList *l = new LinkedList();

    cout << "Adding values at the end of the list: " << endl;
    l->addback(1);
    l->addback(12);
    l->addback(121);
    l->addback(15);
    l->display();

    cout <<"The address of the node containing 1 is: ";
    cout << l->find(0) << endl;

    cout << "Deleting nodes containing 1 and 121 " << endl;
    l->delnode(1);
    l->delnode(121);
    l->display();

    delete l;
    return 0;

}