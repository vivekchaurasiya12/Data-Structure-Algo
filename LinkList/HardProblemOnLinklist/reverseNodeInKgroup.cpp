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

// Function to get the k-th node in a linked list from the current node
Node* getKthNode(Node* temp, int k) {
    k--; // Move k back by one as we want to stop at the k-th node
    // Traverse the list k times or until the end of the list
    while (temp != NULL && k > 0) {
        k--;                // Decrement k for each node we move to
        temp = temp->next;  // Move to the next node
    }
    return temp; // Return the k-th node or NULL if end is reached
}

// Function to reverse a linked list starting from the head node
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

// Function to reverse nodes in groups of size k in the linked list
Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;      // Temporary pointer to traverse the list
    Node* prevNode = NULL;  // Pointer to the last node of the previous group

    // Loop through the linked list to reverse each k-group
    while (temp != NULL) {
        Node* kthNode = getKthNode(temp, k); // Get the k-th node in the current group
        if (kthNode == NULL) {               // If less than k nodes left
            if (prevNode) prevNode->next = temp; // Link the last group's last node
            break;                               // Exit the loop
        }
        Node* nextNode = kthNode->next; // Save the node after the k-th node
        kthNode->next = NULL;           // Temporarily disconnect k-group from the rest

        // Reverse the current k-group
        reverseLinklist(temp);

        // Update head if we're reversing the first group
        if (temp == head) {
            head = kthNode;  // New head of the entire list
        }
        else {
            prevNode->next = kthNode; // Link the previous group's last node to new head
        }

        // Move prevNode to the end of the reversed k-group
        prevNode = temp;
        temp = nextNode; // Move temp to the next node after the k-group
    }
    return head; // Return the new head of the modified list
}

// Function to display the contents of the linked list
void display(Node* head) {
    Node* temp = head; // Start from the head node
    while (temp != NULL) {      // Traverse each node until reaching the end (NULL)
        cout << temp->data << " "; // Print data of the current node
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a new line after displaying all nodes
}

// Main function
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Input array to be converted to linked list
    Node* head = convertArrayToLinklist(arr);          // Convert array to linked list

    int k = 3;                // Set group size for reversing nodes
    head = reverseKGroup(head, k); // Reverse nodes in groups of k
    display(head);                 // Display the modified linked list
    
    return 0; // End of program
}
