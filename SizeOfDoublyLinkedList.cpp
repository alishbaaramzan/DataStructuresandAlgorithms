#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

class DoublyLinkedList{
    Node* head;
    public:
        DoublyLinkedList(){
            head = NULL;
        }
        void addNode(int data){
            Node* ptr = new Node();

            ptr->data = data;
            ptr->next = head;
            ptr->prev = NULL;

            head = ptr;
        }
        void deleteNode(int d){
            Node* ptr = head;
            Node* prev = NULL;

            if(ptr== NULL){
                cout << "Linked list is empty" << endl;
                return;
            }
            while(ptr!=NULL){
                if(ptr->data == d )
                    break;
                prev = ptr;
                ptr =  ptr->next;
            }
            // handling the case when the double linked list is empty
            if(ptr==NULL){
                cout << "Node not found" << endl;
            }
            // handling the case when node to be deleted is the first node
            if(ptr->prev == NULL){
                ptr->next->prev = NULL;
                head = ptr->next;
                delete ptr;
            }
            // handling the case when node to be deleted is the last node
            if(ptr->next == NULL){
                prev->next = NULL;

                delete ptr;
            }
            // for all other cases
            else{
            prev->next = ptr->next;
            ptr->next->prev = prev;

            delete ptr;
            }
        }
        void traverseForward(){
            Node* ptr = head;
            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
        int size(){
            Node* ptr = head;
            int counter = 0;
            while(ptr!=NULL){
                ptr = ptr->next;
                counter++;
            }
            return counter;
        }
        void reverse() {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        // Swap the prev and next pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (the one that was previously before the current node)
        current = current->prev;
    }

    // Update the head pointer to point to the new first node
    if (temp != NULL) {
        head = temp->prev;
    }
}
};

int main(){
    DoublyLinkedList* dlinkedlist = new DoublyLinkedList();

    dlinkedlist->addNode(1);
    dlinkedlist->addNode(2);
    dlinkedlist->addNode(3);
    dlinkedlist->addNode(4);
    dlinkedlist->addNode(5);

    dlinkedlist->reverse();
    dlinkedlist->traverseForward();

    cout << endl << "Size of the linked list is " << dlinkedlist->size() << endl;

    // dlinkedlist->deleteNode(1);
    // cout << "After deleting node containing the value '1', we have: " << endl;
    // dlinkedlist->traverseForward();


    delete dlinkedlist;
    return 0;
}