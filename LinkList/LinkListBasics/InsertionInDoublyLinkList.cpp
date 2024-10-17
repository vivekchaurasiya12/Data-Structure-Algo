#include <bits/stdc++.h> // Include all standard libraries
using namespace std;

// Define the structure of a Node in the doubly linked list
struct Node {
public:
    int data;      // Stores the data value
    Node* next;    // Pointer to the next node in the list
    Node* back;    // Pointer to the previous node in the list

    // Constructor to initialize all parameters
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor to initialize only data, with next and back as nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array into a doubly linked list
Node* ConvertArrayToDoublyLinklist(vector<int>& arr) {
    // Create the head node using the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Track the previous node for linking

    // Loop through the remaining elements to create nodes and link them
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev); // Create new node
        prev->next = temp; // Link previous node to the current one
        prev = temp; // Update the previous node pointer
    }
    return head; // Return the head of the list
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; // Print each node's data
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

// Insert a new node before the head
Node* insertBeforeHead(Node* head, int value) {
    Node* newNode = new Node(value, head, nullptr); // Create new node
    head->back = newNode; // Update the back pointer of the old head
    return newNode; // Return new node as the new head
}

// Insert a new node before the tail
Node* insertBeforeTail(Node* head, int value) {
    if (head->next == nullptr) { // If the list has only one node
        return insertBeforeHead(head, value); // Insert before head
    }
    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    Node* prev = temp->back; // Get the previous node
    Node* newNode = new Node(value, temp, prev); // Create new node
    prev->next = newNode; // Link previous node to new node
    temp->back = newNode; // Link current tail to new node
    return head; // Return the unchanged head
}

// Insert a new node before the kth element
Node* insertBeforeKthElement(Node* head, int value, int k) {
    if (k == 1) { // If inserting at the head
        return insertBeforeHead(head, value);
    }
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) { // Traverse to the kth element
        count++;
        if (count == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back; // Get the previous node
    Node* newNode = new Node(value, temp, prev); // Create new node
    prev->next = newNode; // Link previous node to new node
    temp->back = newNode; // Link kth element to new node
    return head; // Return the unchanged head
}

// Insert a new node before a given node
void insertBeforeNode(Node* node, int value) {
    Node* prev = node->back; // Get the previous node
    Node* newNode = new Node(value, node, prev); // Create new node
    prev->next = node->back = newNode; // Update the links
}

// Main function
int main() {
    // Initialize a vector with elements
    vector<int> arr = {3, 2, 5, 4, 6};

    // Convert the array into a doubly linked list
    Node* head = ConvertArrayToDoublyLinklist(arr);

    // Perform various insertions
    head = insertBeforeHead(head, 10); // Insert 10 before the head
    head = insertBeforeTail(head, 10); // Insert 10 before the tail
    head = insertBeforeKthElement(head, 190, 2); // Insert 190 before the 2nd element
    insertBeforeNode(head->next, 19); // Insert 19 before the second node

    // Display the final linked list
    display(head);

    return 0;
}
