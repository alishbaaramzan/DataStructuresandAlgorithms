#include <iostream>
using namespace std;

class Node{
    public:
        char data;
        Node *next;
        Node(){}
        Node(char d, Node *ptr){
            data = d;
            next = ptr;
        }
        ~Node(){
            delete next;
        }
};
class Stack{
    Node *top;
    public:
        Stack(){
            top = NULL;
        }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else
            return false;
    }
    bool isFull(){
        Node *ptr = new Node();
        if(ptr==NULL){// system memory is exhausted
            return true;
        }
        else{
            return false;
        }
    }
    void push(char value){
        if(!isFull()){
        Node *ptr = new Node();
        ptr->data = value;
        ptr->next = top;
        top = ptr;
        }
        else{
            std :: cout << "Stack is full" << endl;
        }
    }
    char pop(){
        if(!isEmpty()){
            char val = top->data;
            top = top->next;
            return val;
        }
        else{
            std :: cout << "Stack underflow" << endl;
        }
    }
    bool parenthesisMatching(string exp){
        int i = 0;
        while(exp[i]!='\0'){
            if (isEmpty() && (exp[i]==')' || exp[i]=='}' || exp[i]==']')){
                push(exp[i]);
            }
            else if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' ){
                push(exp[i]);
            }
            else if((exp[i]==')' && top->data=='(') || (exp[i]=='}' && top->data=='{') || (exp[i]==']' && top->data=='[') ){
                pop();
            }  
            i++;    
    }
    if(isEmpty()) return true;
    else return false;
    }
    void stackShow(){
        Node *ptr = top;
        while(ptr!=NULL){
            std :: cout << ptr->data << " ";
            ptr = ptr->next;
                      
        }
        std :: cout << endl;
        delete ptr;     
    }
    ~Stack(){
        delete top;
    }
};
int main(){
    Stack* s = new Stack();
    bool isBalanced = s->parenthesisMatching("[(a+b)-(c-d}/5+9]");
    if(isBalanced){
        cout << "Balanced parenthesis" << endl;
    }
    else{
        cout << "Parenthesis is not balanced " << endl;
    }
    delete s;
    return 0;
}