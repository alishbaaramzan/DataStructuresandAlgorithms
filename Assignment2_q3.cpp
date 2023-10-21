#include <iostream>
using namespace std;

class Node{
    public:
        char parenthesis;
        Node* next;
};
class Stack{
    Node* top;
    public:
        Stack(){
            top = NULL;
        }
    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Check if the stack is full
    bool isFull() {
        // Attempt to allocate memory for a new Node, returns true if allocation fails
        Node* ptr = new Node();
        if (ptr == NULL)
            return true;
        else
            return false;
    }

    // Push a student onto the stack
    void push(char c) {
        if (!isFull()) {
            Node* new_node = new Node();
            new_node->parenthesis = c;
            new_node->next = top;
            top = new_node;

        } else {
            cout << "Stack is full" << endl;
        }
    }

    // Pop a student from the stack
    char pop() {
        if (!isEmpty()) {
            Node* todel = top;
            char popVal = top->parenthesis;
            top = top->next;
            delete todel;
            return popVal;
        } else {
            cout << "Stack is empty" << endl;
            return ' ';
        }
    }

    // Get the marks of the student at the top of the stack
    char topVal() {
        if (!isEmpty()) {
            return top->parenthesis;
        } else {
            return ' ';
        }
    }
    bool isBalanced(string exp) {
    int i = 0;
    
    // Iterate through the characters in the expression
    while (exp[i] != '\0') {
        // If an opening parenthesis is encountered, push it onto the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        // If a closing parenthesis is encountered
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // Check if the stack is empty; if it is, the expression is not balanced
            if (top == NULL) {
                return false;
            } else {
                // Pop the top element from the stack
                char temp = pop();
                // Check if the popped character matches the current closing parenthesis
                if (temp == '(' && exp[i] != ')') return false;
                else if (temp == '{' && exp[i] != '}') return false;
                else if (temp == '[' && exp[i] != ']') return false;
            }
        }
        i++;
    }
    
    // If the stack is empty at the end, the expression is balanced; otherwise, it's not.
    if (top == NULL) {
        return true;
    } 
    else {
        return false;
    }
}
};
int main(){
    Stack stack;

    // Test case 1
    if(stack.isBalanced("{25 + (3 - 6) * 8}"))
        cout << "The expression is balanced" << endl;

    // // Test case 2
    if(stack.isBalanced("7 + 8 * 2"))
        cout << "The expression is balanced" << endl;

    // Test case 3
    if(stack.isBalanced("5 + {(13 + 7) / 8 - 2 * 9"))
        cout << "The expression is balanced" << endl;

    // else
        cout << "The expression is  not balanced" << endl;
    
    return 0;
}