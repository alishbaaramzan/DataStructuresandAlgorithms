#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

};

class LinkedList{
    Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        
        void addNode(int val){
            Node* ptr = new Node();
            ptr->data = val;
            ptr->next = head;

            head = ptr;
        }

        void displayList(){
            Node* ptr = head;

            while(ptr!=NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        void middleElement(){
            Node* ptr1 = head;
            Node* ptr2 = head;
            int count = 0;

            while(ptr1!=NULL){
                if(count%2==1){
                    ptr2 = ptr2->next;
                   // cout << "middle pointer value is " << ptr2->data << endl;
                }
                ptr1 = ptr1->next;
                ++count;
            }
            cout << "Middle Element is " << ptr2->data << endl;
        }
        ~LinkedList(){
            Node* ptr = head;
            while(ptr!=NULL){
                Node* ptr_next = ptr->next;
                delete ptr;
                ptr = ptr_next;
            }
        }
};
int main(){
    LinkedList* list = new LinkedList();
    list->addNode(1);
    list->addNode(2);
    list->addNode(3);
    list->addNode(4);
    list->addNode(5);
    list->middleElement();
    return 0;

    /*
    Time Complexity = O(N)
    */
}