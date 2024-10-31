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
    Node* head = new Node(arr[0]); // Create the head node with the first element
    Node* prev = head;             // Track previous node for linking

    // Loop through the rest of the array to create nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev); // New node with back linked to previous
        prev->next = temp;  // Link previous node to the new one
        prev = temp;        // Move the previous pointer to the new node
    }
    return head; // Return head of doubly linked list
}

// Function to display the elements of the doubly linked list
void display(Node* head) {
    Node* temp = head; // Start from the head
    while (temp != NULL) {
        cout << temp->data << " "; // Print each node's data
        temp = temp->next;         // Move to the next node
    }
    cout << endl;
}
// Function to remove duplicates from a sorted doubly linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) return head; // Edge case: Empty or single node list

    Node* temp = head; // Pointer to traverse the list
    while (temp != NULL && temp->next != NULL) {
        Node* nextNode = temp->next;
        
        // While nextNode exists and has duplicate data, delete duplicates
        while (nextNode != NULL && nextNode->data == temp->data) {
            Node* duplicate = nextNode;  // Temporary pointer to hold the duplicate
            nextNode = nextNode->next;   // Move to the next node
            delete duplicate;            // Delete the duplicate node
        }       
        // Re-link temp to the next unique node
        temp->next = nextNode;
        if (nextNode != NULL) nextNode->back = temp; // Adjust back pointer if nextNode exists
        temp = temp->next; // Move temp to the next unique node
    }
    return head; // Return the updated head
}


// Main function to test the doubly linked list operations
int main() {
    vector<int> arr = {1,1,1,2,3,3,3,4,4,5,6,7}; // Array to convert into a doubly linked list

    Node* head = convertArrayToLinkList(arr); // Convert array to doubly linked list
    head = removeDuplicates(head);            // Remove duplicates from the list
    display(head);                            // Display the modified list
    return 0; // End of program
}
