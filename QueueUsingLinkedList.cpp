#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    ~Node(){
        delete next;
        delete prev;
    }
};

class Queue{
    Node* front;
    Node* back;
    public:
    Queue(){
        front = new Node();
        back = new Node();

        front->prev = NULL;
        front->next = back;

        back->prev = front;
        back->next = NULL;

    }
    
    bool isEmpty(){
        if(front->next==back){
            cout << "Queue is empty" << endl;
            return true;
        }
        else{
            cout << "Queue is not empty" << endl;
            return false;
        }
    }

    bool isFull(){
        Node* newNode = new Node();
        if(newNode == NULL){
            cout << "Queue is full" << endl;
        }
        else{
            cout << "Queue has space that can be filled" << endl;
        }
        delete newNode;
    }

    void display(){
        Node* newNode = new Node();
        newNode = front;
        
        if(!isEmpty()){
            if(newNode!= back){
                cout << newNode->data << " ";
                newNode = newNode->next;
            }
            cout << endl;
        }
        delete newNode;
    }

    ~Queue(){
        delete front;
        delete back;
    }
};
int main(){
    Queue* queue;
    queue->display();

    delete queue;
    return 0;

}