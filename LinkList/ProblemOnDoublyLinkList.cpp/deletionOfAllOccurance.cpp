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

// Function to delete all occurrences of a given key in the doubly linked list
Node* deleteAllOccurance(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            // If node to be deleted is head, update head
            if (temp == head) {
                head = temp->next;
            }

            // Update pointers of neighboring nodes
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if (nextNode) nextNode->back = prevNode;
            if (prevNode) prevNode->next = nextNode;

            // Delete the node and move to the next node
            delete temp;
            temp = nextNode;
        } else {
            temp = temp->next; // Move to next node if current node data != key
        }
    }
    return head;
}

// Main function to test the doubly linked list operations
int main() {
    vector<int> arr = {2, 3, 2, 4, 5, 2, 2, 8, 2}; // Array to convert into a doubly linked list

    Node* head = convertArrayToLinkList(arr); // Convert array to doubly linked list
    head = deleteAllOccurance(head, 2);       // Delete all occurrences of 2
    display(head);                            // Display the modified list

    return 0; // End of program
}
