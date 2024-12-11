#include<iostream>
using namespace std;

// Structure representing a node in the stack
struct stackNode {
    int data;             // Data of the node
    stackNode* next;      // Pointer to the next node in the stack
    int size;             // Size of the stack (unused in this struct)
    
    // Constructor to initialize a stack node
    stackNode(int d) {
        data = d;
        next = NULL;
    }
};

// Stack structure
struct stack {
    stackNode* top;       // Pointer to the top of the stack
    int size;             // Keeps track of the size of the stack

    // Constructor to initialize the stack
    stack() {
        top = NULL;       // Initially, the stack is empty
        size = 0;         // Size is zero
    }

    // Push function to add an element to the stack
    void stackPush(int x) {
        stackNode* element = new stackNode(x); // Create a new node
        element->next = top;                  // Link the new node to the current top
        top = element;                        // Update the top to the new node
        cout << "Element pushed" << "\n";     // Notify the push operation
        size++;                               // Increment the size
    }

    // Pop function to remove the top element from the stack
    int stackPop() {
        if (top == NULL) {                    // Check if the stack is empty
            return -1;                        // Return -1 for empty stack
        }
        int topData = top->data;              // Store the data of the top node
        stackNode* temp = top;                // Temporarily store the top node
        top = top->next;                      // Update the top to the next node
        delete temp;                          // Free memory of the removed node
        size--;                               // Decrement the size
        return topData;                       // Return the popped value
    }

    // Function to get the current size of the stack
    int stackSize() {
        return size;                          // Return the size of the stack
    }

    // Function to check if the stack is empty
    bool stackIsEmpty() {
        return top == NULL;                   // Return true if top is NULL
    }

    // Peek function to view the top element without removing it
    int stackPeek() {
        if (top == NULL) return -1;           // Return -1 if the stack is empty
        return top->data;                     // Return the data of the top node
    }

    // Function to print all elements of the stack
    void printStack() {
        stackNode* current = top;             // Start from the top
        while (current != NULL) {             // Traverse until the end of the stack
            cout << current->data << " ";     // Print the data of each node
            current = current->next;          // Move to the next node
        }
    }
};

int main() {
    stack s;                                  // Create a stack object
    s.stackPush(10);                          // Push 10 onto the stack
    cout << "Element popped: " << s.stackPop() << "\n"; // Pop and print the top element
    cout << "Stack size: " << s.stackSize() << "\n";    // Print the size of the stack
    cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n"; // Check if the stack is empty
    cout << "stack's top element: " << s.stackPeek() << "\n"; // Print the top element
    return 0;                                 // Exit the program
}
