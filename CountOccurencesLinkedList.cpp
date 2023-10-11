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
        int countFrequency(int val){
            return countByRecursion(head,val);
        }
        int countByRecursion(Node*head, int v){
            static int i = 0;
            if(head==NULL){
                return i;
            }
            if(head->data == v){
                i++;
            }
            return countByRecursion(head->next, v);
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
    cout << "Frequency of '1' occuring is " << list->countFrequency(1) << endl;
    return 0;

    
}