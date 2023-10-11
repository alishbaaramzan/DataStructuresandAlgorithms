#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        char prec;
        Node *next;

};

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

    void push(char val, int p){
        if(!isFull()){
            Node *ptr = new Node();
            ptr->data = val;
            ptr->prec = p;
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
            std :: cout << ptr->data << " " << ptr->prec << endl;
            ptr = ptr->next;
        }
        std :: cout << endl;
    }
    // function for converting infix to postfix
    string infixToPostfix(string arr){
        int i = 0;
        string postfix = "";
        while(arr[i]!='\0'){
            if(arr[i]=='+' || arr[i]=='-'){
                if(top==NULL || top->prec <1){
                    push(arr[i],1);
                    i++;
                }
                else{
                    char temp = pop();
                    postfix+=temp;
                }  
            }
            if(arr[i]=='*' || arr[i]=='/'){
                if(top==NULL || top->prec < 2){
                    push(arr[i],2);
                    i++;
                }
                else{
                    char temp = pop();
                    postfix+=temp;
                }
            }
            else{
                postfix += arr[i];
                i++;
            }
        }
        while(top!=NULL){
            char temp = pop();
            postfix += temp;
        }
        return postfix;
    }
    ~Stack(){
        delete top;
    }
};
int main(){
    Stack *s = new Stack();
    string infix = "p-q-r/a";
    string postfix = s->infixToPostfix(infix);
    cout << "Infix expression is: " << infix << endl;
    cout << "Postfix expression is: " << postfix << endl;
    delete s;
    return 0;
}