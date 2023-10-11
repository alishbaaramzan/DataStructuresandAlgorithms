#include<iostream>
using namespace std;

class Queue{
    int size;
    int* arr;
    int front;
    int back;

    public:

    // adjusting size of array
    Queue(int s){
       size = s;
       front = 0;
       back = 0;
       arr = new int[size];
    }

    void display(){
        if(isEmpty()){
            cout << " Queue is empty" << endl;
        }
        else{
        for (int i = front; i < back; i++){
            cout << arr[i]<< " ";
        }
        cout << endl;
        }
    }

    bool isEmpty(){
        if(front==back) return true;
        else return false;
    }

    bool isFull(){
        if(back==size) return true;
        else return false;
    }

    void enqueue(int elem){
        if(!isFull()){
            arr[back] = elem;
            back++;
        }
        else{
            cout << "Queue is full " << endl;
        }
    }

    void dequeue(){
        if(!isEmpty()){
            cout << "Element " << arr[front] << " has been dequeued" << endl;
            front++;
            size++;
        }
        else{
            cout << "Queue is empty";
        }
    }
};
int main(){
    Queue queue(8);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(3);
    queue.enqueue(3);
    queue.enqueue(3);
    queue.enqueue(3);
    queue.enqueue(3);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.display();

    queue.dequeue();
    queue.display();  

    queue.enqueue(4);
    queue.display(); 

    return 0;
}