#include <bits/stdc++.h>
using namespace std;

// Queue class using circular array
class Queue {
    int* arr;             // Dynamic array to store queue elements
    int start, end;       // Indices for the front and rear of the queue
    int currSize;         // Current number of elements in the queue
    int maxSize;          // Maximum size of the queue

public:
    // Default Constructor
    Queue() {
        maxSize = 16;          // Set default maximum size to 16
        arr = new int[maxSize]; // Allocate memory for the queue
        start = -1;            // Initially, queue is empty
        end = -1;
        currSize = 0;          // No elements in the queue initially
    }

    // Parameterized Constructor
    Queue(int maxSize) {
        this->maxSize = maxSize; // Set custom maximum size
        arr = new int[maxSize];  // Allocate memory for the queue
        start = -1;             // Initially, queue is empty
        end = -1;
        currSize = 0;           // No elements in the queue initially
    }

    // Destructor to release memory
    ~Queue() {
        delete[] arr;           // Free the dynamically allocated memory
    }

    // Push Operation to add an element to the queue
    void push(int newElement) {
        if (currSize == maxSize) { // Check if the queue is full
            cout << "Queue is full. Cannot push " << newElement << endl;
            return;
        }
        if (end == -1) {         // If the queue is empty
            start = 0;           // Initialize start and end
            end = 0;
        } else {
            end = (end + 1) % maxSize; // Circular increment of end index
        }
        arr[end] = newElement;   // Add the new element to the queue
        cout << "The element pushed is " << newElement << endl;
        currSize++;              // Increment the size of the queue
    }

    // Pop Operation to remove an element from the queue
    int pop() {
        if (currSize == 0) {     // Check if the queue is empty
            cout << "Queue is empty. Cannot pop." << endl;
            return -1;           // Return a sentinel value
        }
        int popped = arr[start]; // Store the front element to return
        if (currSize == 1) {     // If the queue has only one element
            start = -1;          // Reset start and end indices
            end = -1;
        } else {
            start = (start + 1) % maxSize; // Circular increment of start index
        }
        currSize--;              // Decrement the size of the queue
        return popped;           // Return the popped element
    }

    // Top Operation to get the front element of the queue
    int top() {
        if (currSize == 0) {     // Check if the queue is empty
            cout << "Queue is empty. No top element." << endl;
            return -1;           // Return a sentinel value
        }
        return arr[start];       // Return the front element
    }

    // Size Operation to get the current size of the queue
    int size() {
        return currSize;         // Return the size of the queue
    }

    // Check if the Queue is Empty
    bool isEmpty() {
        return currSize == 0;    // Return true if size is zero
    }
};

int main() {
    Queue q(6); // Create a queue with a maximum size of 6

    // Push some elements into the queue
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    // Display the front element and size of the queue
    cout << "The peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.size() << endl;

    // Remove the front element and display it
    cout << "The first element to be deleted: " << q.pop() << endl;

    // Display the front element and size of the queue after deletion
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.size() << endl;

    return 0;
}
