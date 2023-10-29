#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node *next;

};
int prec(char c){
    if(c == '^') return 3;
    else if (c =='*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}
class Stack{
    Node *top;
    public:
        Stack(){
            top = NULL;
        }
    bool isEmpty(){
        if(top==NULL) return true;
        else return false;
    }

    bool isFull(){
        Node *ptr = new Node();
        if(ptr==NULL) return true;
        else return false;
    }

    void push(char val){
        if(!isFull()){
            Node *ptr = new Node();
            ptr->data = val;
            ptr->next = top;
            top = ptr;
        }
        else std :: cout << "Stack overflow" << endl;
    }

    char pop(){
        if(!isEmpty()){
            char val = top->data;
            top = top->next;
            return val;
        }
        else std :: cout << "Stack underflow" << endl;
    }

    void stackDisplay(){
        Node *ptr = top;
        while(ptr!=NULL){
            std :: cout << ptr->data << endl;
            ptr = ptr->next;
        }
        std :: cout << endl;
    }
    // function for converting infix to postfix
    string infixToPostfix(string arr){
        int i = 0;
        string postfix = "";
        while(arr[i] != '\0'){
            if((arr[i] >='a' && arr[i] <='z') || (arr[i] >='a' && arr[i] <='z') || (arr[i] >='0' && arr[i] <='9')){
                postfix += arr[i];
            }
            else if(arr[i]=='(' || arr[i]=='{' || arr[i] == '[')
                push(arr[i]);
            else if (arr[i]==')' || arr[i]=='}' || arr[i] == ']'){
                while(top->data != '(' && top->data != '{' && top->data != '[')
                    postfix += pop();
                pop();
            }
            else{
                while(prec(arr[i]) <= prec(top->data))
                    postfix += pop();
                push(arr[i]);
            }
            i++;
        }
        return postfix;
    }
    
};
int main(){
    Stack *s = new Stack();
    string infix = "(p-q-r/a+b)";
    string postfix = s->infixToPostfix(infix);
    cout << "Infix expression is: " << infix << endl;
    cout << "Postfix expression is: " << postfix << endl;
    delete s;
    return 0;
}