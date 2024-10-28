#include <bits/stdc++.h>
using namespace std;

// Define a structure for Node
struct Node {
   public:
       int data;    // Data value of the node
       Node* next;  // Pointer to the next node

       // Constructor to initialize both data and next pointer
       Node(int data1, Node* next1) {
           data = data1;
           next = next1;
       }

       // Constructor to initialize only data, with next set to nullptr
       Node(int data1) {
           data = data1;
           next = nullptr;
       }
};

// Function to convert a vector into a linked list
Node* convertArrayToLinklist(vector<int> &arr) {
    // Initialize the head with the first element
    Node* head = new Node(arr[0]);
    Node* mover = head;  // Pointer to traverse and add nodes

    // Loop through the vector starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node for each element
        mover->next = temp;            // Link the new node to the list
        mover = mover->next;           // Move the pointer to the new end of the list
    }
    return head; // Return the head of the created linked list
}

// Function to find the middle element of the linked list
Node* middleElement(Node* head) {
    Node* slow = head; // `slow` pointer moves one step at a time
    Node* fast = head; // `fast` pointer moves two steps at a time

    // Traverse the list with `fast` and `slow` pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move `slow` by one node
        fast = fast->next->next;     // Move `fast` by two nodes
    }

    // When `fast` reaches the end, `slow` will be at the middle
    return slow;
}

// Main function
int main() {
    vector<int> arr = {1, 2, 1, 8}; // Input array to be converted to linked list
    Node* head = convertArrayToLinklist(arr); // Convert array to linked list

    // Find and print the middle element of the list
    Node* newnode = middleElement(head);
    cout << "Middle element: " << newnode->data << endl;
    
    
    
    return 0;
}
