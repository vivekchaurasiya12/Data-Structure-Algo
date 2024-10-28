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
        mover = mover->next;            // Move the pointer to the new end of the list
    }
    return head; // Return the head of the created linked list
}

// Function to display the contents of the linked list
void display(Node* head) {
    Node* temp = head; // Start from the head node
    while (temp != NULL) { // Traverse each node until reaching the end (NULL)
        cout << temp->data << " "; // Print data of the current node
        temp = temp->next;         // Move to the next node
    }
}

// Function to reverse a linked list
Node* reverseLinklist(Node* head) {
    Node* temp = head; // Temporary pointer to traverse the list
    Node* prev = NULL; // Pointer to store the previous node (initially NULL)

    // Loop to reverse the linked list
    while (temp != NULL) {
        Node* front = temp->next; // Save the next node
        temp->next = prev;        // Reverse the current node's pointer
        prev = temp;              // Move prev to the current node
        temp = front;             // Move temp to the next node
    }
    return prev; // prev becomes the new head of the reversed list
}

// Main function
int main() {
    vector<int> arr = {4, 2, 6, 3, 4, 1, 9}; // Input array to be converted to linked list
    Node* head = convertArrayToLinklist(arr); // Convert array to linked list
    head = reverseLinklist(head);             // Reverse the linked list
    display(head);                            // Display the reversed list

    return 0;
}
