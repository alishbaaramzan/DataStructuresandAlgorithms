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

        void deleteFromStart(){
            // linked list is empty and no node to delete
            if(head==tail){
        
                cout << "List is empty" << endl;
            }
            // only one node present
            if(head->next->next == NULL){
                Node* ptr = head->next;
                head->next = ptr->next;
                delete ptr;
            }
            else{
                 Node* ptr =  head->next;
                head->next = ptr->next;
                (ptr->next)->prev = head;
                delete ptr;
            }
            // Time Complexity = O(1)
        }

        void deleteFromEnd(){
            // check if list is empty
            if(head==tail){
                cout << "List is empty" << endl;
            }
            else{
                Node* ptr = tail->prev;
                ptr->next = NULL;
                delete tail;
                tail = ptr;
            }
            // Time Complexity = O(1)
        }

        void deleteatValue(int val){
            Node* prev_ptr = head;
            Node* curr_ptr = head->next;

            if(head==tail){
                cout << "Linked list is empty" << endl;
            }
            if(tail->data==val){
                deleteFromEnd();
            }
            else{
                 while(curr_ptr!= NULL){
                if(curr_ptr->data== val) break;
                prev_ptr = curr_ptr;
                curr_ptr = curr_ptr->next;
            }
            prev_ptr->next = curr_ptr->next;
            (curr_ptr->next)->prev = prev_ptr;

            delete curr_ptr;
            }
        }
};
int main(){
    DoublyLinkedList* dlinkedlist = new DoublyLinkedList();
    dlinkedlist->addNodeAtEnd(1);
    dlinkedlist->addNodeAtEnd(2);
    dlinkedlist->addNodeAtEnd(3);
    dlinkedlist->addNodeAtEnd(4);
    dlinkedlist->addNodeAtEnd(5);
    dlinkedlist->display();

    // dlinkedlist->deleteFromStart();
    // dlinkedlist->deleteFromEnd();
    dlinkedlist->deleteatValue(5);
    dlinkedlist->display();

    delete dlinkedlist;
    return 0;
}