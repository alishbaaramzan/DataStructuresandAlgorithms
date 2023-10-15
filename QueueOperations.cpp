#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
class Queue{
    public:
        Node* head;
        Node* tail;
        Queue(){
            head = new Node();
            head->next = NULL;
            tail = head;
        }
        void enqueue(int val){
            Node* new_node = new Node();
            new_node->data = val;

            // if the queue is empty
            if(head->next==NULL){
                head->next = new_node;
                new_node->next = NULL;
                tail = new_node;
            }
            else{
                tail->next = new_node;
                new_node->next = NULL;
                tail = new_node;
            }
        }
        void dequeue(){
            // if queue is empty
            if(head->next == NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                Node* deqptr = head->next;
                head->next = head->next->next;
                delete deqptr;
            }
        }
        void display(){   
            if(head->next==NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                Node* ptr = head->next;
                while(ptr!=NULL){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
                cout << endl;
            }
        }
        int length(){
            int len = 0;
            if(head->next==NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                Node* ptr = head->next;
                while(ptr!=NULL){
                    len++;
                    ptr = ptr->next;
                }
            }
            return len;
        }
};
int main(){
    Queue* queue = new Queue();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->display(); 
    cout << queue->length()<< " is the length"<< endl;

    queue->dequeue();
    queue->dequeue();
    queue->display();
    cout << queue->length()<< " is the length"<< endl;

    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->display();
    cout << queue->length()<< " is the length"<< endl;


    delete queue;
    return 0;
}
