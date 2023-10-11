#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
};
class Stack{
    Node* top;
    public:
        Stack(){
            top = NULL;
        }
        void push(char c){
            Node* new_node = new Node();
            if(new_node!=NULL){
                Node* new_node = new Node();
                new_node->data = c;
                new_node->next = top;
                top = new_node;
                cout << "pushed " << top->data << endl;
            }
            else{
                cout << "Stack is overflow" << endl;
            }
        }
        char pop(){
            if(top!=NULL){
                Node* toDelete = top;
                char top_val = top->data;
                top = top->next;
                delete toDelete;
                cout << "Popped " << top_val << endl;
                return top_val;
            }
            else{
                cout << "Stack is underflow" << endl;
            }
        }
        string reverseString(string s){
            int i = 0;
            string reversed = "";
            while(s[i]!='\0'){
                push(s[i]);
                i++;
            }
            //i = 0;
            while(top!=NULL){
                reversed +=pop();
                i++;
            }
            return reversed;
        }
};
int main(){
    Stack* stack = new Stack();
    string r = stack->reverseString("ayesha");
    cout << r << endl;
    delete stack;
    return 0;
}