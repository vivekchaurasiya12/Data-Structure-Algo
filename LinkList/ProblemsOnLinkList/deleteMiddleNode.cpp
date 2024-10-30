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

// Function to display the linked list
void display(Node* head){
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " "; // Print each node's data
        temp = temp->next;         // Move to the next node
    }
}

// Function to delete the middle node of the linked list
Node* deleteMiddleNode(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;           // Slow pointer for one-step traversal
    Node* fast = head;           // Fast pointer for two-step traversal

    // Move the fast pointer two steps ahead initially
    fast = fast->next->next;

    // Traverse the list until fast reaches the end
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move slow pointer one step
        fast = fast->next->next;  // Move fast pointer two steps
    }

    // Delete the middle node
    Node* middleNode = slow->next;    // Middle node is the next of slow
    slow->next = slow->next->next;    // Link previous node to the node after middle
    delete middleNode;                // Delete the middle node
    return head;                      // Return updated list head
}

// Main function
int main() {
    vector<int> arr = {1, 2, 1, 8, 7, 3, 2};    // Input array to be converted to linked list
    Node* head = convertArrayToLinklist(arr); // Convert array to linked list

    // Delete the middle node and display the updated list
    Node* newnode = deleteMiddleNode(head);
    display(head);

    return 0;
}
