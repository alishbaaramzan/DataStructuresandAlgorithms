#include <iostream>
using namespace std;

// implementing stack using an array
class Stack{
    int size;
    int top;
    int *arr;

    public:
        Stack(int size){
            this->size = size;
            this->top = -1;
            this->arr = new int[this->size];
        }

        // function to check if stack is empty
        // T(N) = O(1)
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
        

        // function to check if stack is full
        // T(N) = O(1)
        bool isFull(){
            if(top==size-1){
                return true;
            }
            else{
                return false;
            }
        }

        // implementing function to add a frame to stack
        // T(N) = O(1)
        void push(int data){
            if(!isFull()){
                arr[++top] = data;
            }
            else{
                cout << "Stack overflow" << endl;
            }
        }

        // implementing function to remove a frame from stack
        // T(N) = O(1)
        void pop(){
            if(!isEmpty()){
                top--;
            }
            else{
                cout << "Stack is empty" << endl;
            }
        }

        // function to get a value from a certain position
        // T(N) = O(1)
        int peek(int position){
            if(top-position+1 >= 0){
            return arr[top-position+1];
            }
            else{
                cout << "No value at position " << position << endl;
            }
        }

        // T(N) = O(1)
        int topElement(){
            return arr[top];
        }

        // T(N) = O(1)
        int bottomElement(){
            return arr[0];
        }
    ~Stack(){
        delete arr;
    }

};
int main(){
    Stack *stack = new Stack(1);
    stack->pop(); // it should tell me stack is empty
    stack->push(1);
    int peek_value = stack->peek(0); // should give me 1
    int peek_value2 = stack->peek(2); // should give me error
    stack->push(3); // should tell me that stack is full

    delete stack;
    return 0;
}   