#include <bits/stdc++.h> // Including all standard libraries for convenience
using namespace std;

// Define the structure of a Node in the doubly linked list
struct Node {
public:
    int data;      // Data value of the node
    Node* next;    // Pointer to the next node
    Node* back;    // Pointer to the previous node

    // Constructor with parameters for data, next, and back pointers
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor to initialize only data, with next and back set to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array into a doubly linked list
Node* convertArrayToLinkList(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Track the previous node for linking

    // Loop through the rest of the array to create nodes
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with the current element, linking it to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Link the previous node to the new one
        prev = temp;        // Move the previous pointer to the new node
    }
    return head; // Return the head of the doubly linked list
}

// Function to reverse the doubly linked list
Node* reveseDoublyLinklist(Node* head) {
    Node* temp = head;  // Start with the head node
    Node* last = NULL; // Initialize last as null

    // Traverse the list, swapping next and back pointers for each node
    while (temp != NULL) {
        last = temp->back;     // Keep track of the previous node
        temp->back = temp->next; // Swap the back and next pointers
        temp->next = last;      // Continue swapping
        temp = temp->back;      // Move to the next node (previous in original order)
    }
    return last->back; // Return the new head of the reversed list
}

// Function to display the elements of the linked list
void display(Node* head) {
    Node* temp = head; // Start from the head
    while (temp != NULL) {
        cout << temp->data << " "; // Print each node's data
        temp = temp->next;         // Move to the next node
    }
}

// Main function to test the doubly linked list operations
int main() {
    // Initialize an array of integers
    vector<int> arr = {3, 5, 6, 8, 2};

    // Convert the array into a doubly linked list
    Node* head = convertArrayToLinkList(arr);

    // Display the original list
    display(head);
    cout << endl;

    // Reverse the doubly linked list
    head = reveseDoublyLinklist(head);

    // Display the reversed list
    display(head);

    return 0; // End of program
}
