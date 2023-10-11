#include <iostream>
using namespace std;

class Node{
    public:
        char data;
        Node *next;
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
            Node *ptr = new Node;
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
            std :: cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std :: cout << endl;
    }

    bool MultipleParenthesisMatching(char *arr){
        int i = 0;
        bool check = true;
        while(arr[i]!='\0'){
            if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
                push(arr[i]);
            }
            if(arr[i]==')' || arr[i]=='}' || arr[i]==']'){
                if(!isEmpty()){
                    if(arr[i]==')' && top->data =='('){
                        char temp = pop();
                    }
                    else if(arr[i]=='}' && top->data =='{'){
                        char temp = pop();
                    }
                    else if(arr[i]== ']' && top->data =='['){
                        char temp = pop();
                    }
                    else{
                        check = false;
                        break;
                    }
                }
                else{
                    check = false;
                    break;
                }
            }
            
            i++;
        }
        if(!isEmpty()){
            check = false;
        }
        return check;
    }
    ~Stack(){
        delete top;
    }
};
int main(){
    Stack *s = new Stack();
    char *arr = "[8*9+{4-(1+1)*4}"; // not balanced
    bool p_match = s->MultipleParenthesisMatching(arr);
    if(p_match==true){
        std :: cout << "Balanced expression" << endl;
    }
    else{
        std :: cout << "Not a balanced expression" << endl;
    }
    delete s;
    return 0;

}