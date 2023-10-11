#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    class Node *next;
    Node(){}
    Node(int data, class Node* ptr){
            this->data = data;
            next = ptr;
        }
    ~Node(){
        delete next;
    }
};

class Stack{
    Node *top;
    int check;
    public:
        Stack(){
            top = new Node();
            top = NULL;
            check = 0;
        }
    int get_check(){
        return check;
    }

    // function to check if stack is empty
    // T(N) = O(1)
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    // function to check if stack is full
    // T(N) = O(1)
    bool isFull(){
        if(check>4000){
            return true;
        }
        else{
            return false;
        }
    }

    // function to push a frame into stack
    // T(N) = O(1)
    void push(int value){
        if(!isFull()){
        Node *ptr = new Node();
        ptr->next = top;
        top = ptr;
        ptr->data = value;
        check++;
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }

    // function to pop a frame from stack
    // T(N) = O(1)
    int pop(){
        if(!isEmpty()){
        //Node *ptr = new Node();
        //ptr = top;
        int val = top->data;
        top = top->next;
        check--;
        //delete ptr;
        return val;
        }

    }

    // function to peek a value at a certain position
    // T(N) = O(n)
    int peek(int pos){
        if(pos<= check){
        Node *ptr = new Node();
        ptr = top;
        for(int i = 1; i < pos; i++){
            ptr = ptr->next;
        }
        return ptr->data;
        }
        else{
            cout << "No value at position " << pos << endl;
        }
    }

    // T(N) = O(1)
    int topElement(){
        return top->data;
    }

    // T(N) = O(n)
    int bottomElement(){
        Node *ptr = top;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        return ptr->data;
    }
    ~Stack(){
        delete top;
    }
};
int main(){
    Stack *stack = new Stack();
    stack->push(23);
    stack->push(24);
    stack->push(45);
    stack->push(99);

    // checking push functions
    for(int i = 1; i <= stack->get_check(); i++){
        cout << stack->peek(i) << " ";
    }
    cout << endl;

    // checking pop function
   int val = stack->pop();
    for(int i = 1; i <= stack->get_check(); i++){
        cout << stack->peek(i) << " ";
    }
    cout << endl;

    // printing top and bottom elements
    cout << "Top element: " << stack->topElement() << endl;
    cout << "Bottom element: " << stack->bottomElement() << endl;
    delete stack;
    return 0;
}