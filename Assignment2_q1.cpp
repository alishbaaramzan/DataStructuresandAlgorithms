#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

class Dequeue {
    int arr[MAX_SIZE]; // Array to store deque elements
    int front;         // Index of the front of the deque
    int rear;          // Index of the rear of the deque

public:
    Dequeue() {
        front = -1;
        rear = -1; // Initialize deque as empty
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) // Check if the deque is empty
            return true;
        else 
            return false;
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front); // Check if the deque is full
    }

    void pushfront(int val) {
        if (isFull()) {
            cout << "Dequeue is full " << endl; // Display an error message if the deque is full
        } else if (isEmpty()) {
            front = rear = 0;
            arr[front] = val;
        } else {
            if (front > 0) {
                front = front - 1;
                arr[front] = val; // Add the element to the front of the deque
            } else {
                int j = rear + 1;
                rear++;
                while (j > 0) {
                    arr[j] = arr[j - 1]; // Shift elements to make space
                    j--;
                }
                arr[j] = val; // Add the element to the front
            }
        }
    }

    void pushback(int val) {
        if (isFull()) {
            cout << "Dequeue is full " << endl; // Display an error message if the deque is full
        } else if (isEmpty()) {
            front = rear = 0;
            arr[rear] = val;
        } else {
            if (rear + 1 < MAX_SIZE) {
                rear = rear + 1;
                arr[rear] = val; // Add the element to the back of the deque
            } else {
                int j = front - 1;
                front--;
                while (j < MAX_SIZE - 2) {
                    arr[j] = arr[j + 1]; // Shift elements to make space
                }
                arr[rear] = val; // Add the element to the back
            }
        }
    }

    int popfront() {
        if (isEmpty()) {
            cout << "Dequeue is empty. No element to pop." << endl; // Display an error message if the deque is empty
        } else {
            int val_to_pop = arr[front]; // Get the value to pop from the front
            front = front + 1; // Update the front index
            return val_to_pop; // Return the popped value
        }
    }

    int popback() {
        if (isEmpty()) {
            cout << "Dequeue is empty. No element to pop." << endl; // Display an error message if the deque is empty
        } else {
            int val_to_pop = arr[rear]; // Get the value to pop from the back
            rear = rear - 1; // Update the rear index
            return val_to_pop; // Return the popped value
        }
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " "; // Display the elements of the deque
        }
        cout << endl;
    }
};

int main() {
    Dequeue deque; // Create a deque object

    // Test Case 1: Push elements to the front of the deque
    deque.pushfront(1);
    deque.pushfront(2);
    deque.pushfront(3);

    cout << "Deque after pushing to the front: ";
    deque.display(); // Should display: 3 2 1

    // Test Case 2: Push elements to the back of the deque
    deque.pushback(4);
    deque.pushback(5);
    deque.pushback(6);

    cout << "Deque after pushing to the back: ";
    deque.display(); // Should display: 3 2 1 4 5 6

    // Test Case 3: Pop elements from the front and the back
    int poppedFront = deque.popfront();
    int poppedBack = deque.popback();

    cout << "Popped element from the front: " << poppedFront << endl; // Should display: 3
    cout << "Popped element from the back: " << poppedBack << endl; // Should display: 6

    cout << "Deque after popping elements: ";
    deque.display(); // Should display: 2 1 4 5

    return 0;
}
