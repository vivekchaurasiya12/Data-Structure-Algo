#include<bits/stdc++.h> 
using namespace std;

// Define the QueueNode class to represent a node in the queue
class QueueNode {
public: 
    int val;  // The value stored in the node
    QueueNode *next;  // Pointer to the next node in the queue
    
    // Constructor to initialize the node with a value
    QueueNode(int data) {
       val = data;
       next = nullptr;  // Set the next pointer to nullptr by default
    }
};  

// Declare pointers to the front and rear (tail) of the queue
QueueNode *Front = nullptr, *Rare = nullptr;

// Define the Queue class with necessary methods
class Queue {
public:
    int size = 0;  // Variable to store the current size of the queue
    bool Empty();  // Method to check if the queue is empty
    void Enqueue(int value);  // Method to add an element to the queue
    void Dequeue();  // Method to remove an element from the queue
    int Peek();  // Method to return the value of the front element without removing it
};

// Method to check if the queue is empty
bool Queue::Empty() {
    return Front == nullptr;  // If the front is nullptr, the queue is empty
}

// Method to peek at the front element of the queue
int Queue::Peek() {
    if (Empty()) {  // If the queue is empty, return -1 and print a message
        cout << "Queue is Empty" << endl;
        return -1;
    } else {
        return Front->val;  // Return the value at the front of the queue
    }
}

// Method to enqueue (add) an element to the queue
void Queue::Enqueue(int value) {
    QueueNode *Temp = new QueueNode(value);  // Create a new node with the given value
    if (Temp == nullptr) {  // Check if memory allocation fails (heap exhausted)
        cout << "Queue is Full" << endl;
    } else {
        if (Front == nullptr) {  // If the queue is empty
            Front = Temp;  // Both front and rear point to the new node
            Rare = Temp;
        } else {
            Rare->next = Temp;  // Link the new node to the last node
            Rare = Temp;  // Move the rear pointer to the new node
        }
        cout << value << " Inserted into Queue" << endl;  // Print the inserted value
        size++;  // Increment the size of the queue
    } 
}

// Method to dequeue (remove) an element from the queue
void Queue::Dequeue() {
    if (Front == nullptr) {  // If the queue is empty, print a message
        cout << "Queue is Empty" << endl;
    } else {
        cout << Front->val << " Removed From Queue" << endl;  // Print the removed value
        QueueNode *Temp = Front;  // Temporarily store the front node
        Front = Front->next;  // Move the front pointer to the next node
        delete Temp;  // Delete the old front node to free memory
        size--;  // Decrement the size of the queue
    }  
}

int main() {
    Queue Q;  // Create a Queue object
    
    // Perform enqueue operations
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);

    // Perform a dequeue operation
    Q.Dequeue();

    // Print the size of the queue
    cout << "The size of the Queue is " << Q.size << endl;
    
    // Peek at the front element and print it
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;

    return 0;
}
