#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1; // Stack to store elements as they are pushed
    stack<int> s2; // Auxiliary stack to reverse order for dequeue operations

public:
    // Constructor for the queue
    MyQueue() {
    }

    // Pushes an element into the queue
    void push(int x) {
        s1.push(x); // Always push new elements onto stack s1
    }

    // Removes and returns the front element of the queue
    int pop() {
        // If stack s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top()); // Move elements from s1 to s2
                s1.pop();          // Remove elements from s1
            }
        }
        // If s2 is still empty, the queue is empty
        if (s2.empty()) {
            return -1; // Return -1 as an indication of an empty queue
        }
        int front = s2.top(); // The top of s2 represents the front of the queue
        s2.pop();             // Remove the front element
        return front;
    }

    // Returns the front element of the queue without removing it
    int peek() {
        // Transfer elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top()); // Move elements from s1 to s2
                s1.pop();          // Remove elements from s1
            }
        }
        // If s2 is still empty, the queue is empty
        if (s2.empty()) {
            return -1; // Return -1 as an indication of an empty queue
        }
        return s2.top(); // The top of s2 represents the front of the queue
    }

    // Checks if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty(); // Queue is empty if both stacks are empty
    }
};

int main() {
    MyQueue q;

    q.push(1); // Pushes 1 into the queue
    q.push(2); // Pushes 2 into the queue
    q.push(3); // Pushes 3 into the queue

    cout << "Front element: " << q.peek() << endl; // Prints the front element (1)

    cout << "Removed element: " << q.pop() << endl; // Removes and prints the front element (1)
    cout << "Removed element: " << q.pop() << endl; // Removes and prints the next front element (2)

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Checks if queue is empty

    q.push(4); // Pushes 4 into the queue

    cout << "Front element: " << q.peek() << endl; // Prints the new front element (3)

    return 0;
}
