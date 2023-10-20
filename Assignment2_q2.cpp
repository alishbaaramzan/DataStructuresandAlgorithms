#include <iostream>
using namespace std;

// Node class to represent each student
class Node {
public:
    string name;
    float marks;
    Node* next;
};

// Stack class to manage the students
class Stack {
    Node* top;
    int size;

public:
    // Constructor to initialize the stack
    Stack() {
        top = NULL;
        size = 0;
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
    void push(string name, float marks) {
        if (!isFull()) {
            Node* new_node = new Node();
            new_node->name = name;
            new_node->marks = marks;
            new_node->next = top;
            top = new_node;
            size++;
        } else {
            cout << "Stack is full" << endl;
        }
    }

    // Pop a student from the stack
    void pop() {
        if (!isEmpty()) {
            Node* todel = top;
            top = top->next;
            delete todel;
            size--;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    // Get the marks of the student at the top of the stack
    float topVal() {
        if (!isEmpty()) {
            return top->marks;
        } else {
            return -1;
        }
    }

    // Display all students in the stack
    void display() {
        if (!isEmpty()) {
            Node* ptr = top;
            while (ptr != NULL) {
                cout << ptr->name << ": " << ptr->marks << endl;
                ptr = ptr->next;
            }
        } else {
            cout << "No students to display" << endl;
        }
    }

    // Display the top three students with the highest marks
    void displayTopThree() {
        Node* arr = new Node[3];
        float max = 100;
        for (int i = 2; i >= 0; i--) {
            Node* ptr = top;
            arr[i].marks = 0.0;
            while (ptr != NULL) {
                if (ptr->marks > arr[i].marks && ptr->marks < max) {
                    arr[i] = *ptr;
                }
                ptr = ptr->next;
            }
            max = arr[i].marks;
        }
        // Display the top three students
        for (int i = 2; i >= 0; i--) {
            cout << arr[i].name << ": " << arr[i].marks << endl;
        }
        delete[] arr;
    }
};

int main() {
    Stack allStudents; // Create a stack to store student data

    // Test Case 1: Push students onto the stack
    allStudents.push("Muhammad", 99.5);
    allStudents.push("Ayesha", 88.0);
    allStudents.push("Ali", 92.5);
    allStudents.push("Fatima", 78.3);
    allStudents.push("Hassan", 98.7);

    cout << "All students:" << endl;
    allStudents.display();

    // Test Case 2: Display top three students
    cout << "Top three students:" << endl;
    allStudents.displayTopThree();

    return 0;
}