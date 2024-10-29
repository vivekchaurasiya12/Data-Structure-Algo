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

// Helper function for adding one to the linked list
int recursiveFunction(Node* temp) {
    // Base case: if node is NULL, return carry as 1 for the addition
    if(temp == NULL){
        return 1;
    }
    // Recursively add one to the last node, propagating carry backwards
    int carry = recursiveFunction(temp->next);
    temp->data = temp->data + carry;

    // If the current node's data is less than 10, no carry is needed
    if(temp->data < 10){
        return 0;
    }
    // If the current node's data is 10 or more, set it to 0 and propagate carry
    temp->data = 0;
    return 1;
}

// Function to add one to the entire linked list
Node* addOne(Node* head) {
    int carry = recursiveFunction(head); // Call helper function for carry

    // If there's still a carry after processing all nodes, add new head
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    // If no carry remains, return the original head
    return head;
}

// Main function
int main() {
    vector<int> arr = {7,9,9};      
    Node* head = convertArrayToLinklist(arr); 
    head = addOne(head);            
    display(head);                   
    return 0;
}
