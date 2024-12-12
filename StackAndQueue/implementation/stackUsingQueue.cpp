#include<bits/stdc++.h>
using namespace std;

// Stack class using a single queue for implementation
class Stack {
    queue<int> q;  // Declare a queue to simulate stack behavior

public:
    // Push an element into the stack
    void Push(int x) {
        int s = q.size();  // Get the current size of the queue
        q.push(x);  // Push the new element into the queue
        
        // Rotate the queue to simulate stack behavior
        for (int i = 0; i < s; i++) {
            q.push(q.front());  // Move the front element to the back
            q.pop();  // Remove the front element
        }
    }

    // Remove and return the top element of the stack
    int Pop() {
        int n = q.front();  // Get the front element (top of the stack)
        q.pop();  // Remove the front element
        return n;  // Return the removed element
    }

    // Get the top element of the stack without removing it
    int Top() {
        return q.front();  // Front of the queue represents the top of the stack
    }

    // Get the size of the stack
    int Size() {
        return q.size();  // Return the size of the queue
    }
};

int main() {
    Stack s;  // Create a Stack object

    // Push elements into the stack
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);

    // Display the top element of the stack
    cout << "Top of the stack: " << s.Top() << endl;

    // Display the size of the stack before removing an element
    cout << "Size of the stack before removing element: " << s.Size() << endl;

    // Remove the top element of the stack and display it
    cout << "The deleted element is: " << s.Pop() << endl;

    // Display the top element after removing an element
    cout << "Top of the stack after removing element: " << s.Top() << endl;

    // Display the size of the stack after removing an element
    cout << "Size of the stack after removing element: " << s.Size() << endl;
}
