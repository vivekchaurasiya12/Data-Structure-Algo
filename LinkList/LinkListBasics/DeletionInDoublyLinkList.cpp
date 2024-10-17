#include <bits/stdc++.h>
using namespace std;

// Define the structure of a Node in the doubly linked list
struct Node {
public:
    int data;      // Stores the data value
    Node* next;    // Pointer to the next node in the list
    Node* back;    // Pointer to the previous node in the list

    // Constructor with all parameters
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data parameter, initializes next and back to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array into a doubly linked list
Node* ConvertArrayToDoublyLinklist(vector<int>& arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Keep track of the previous node for linking

    // Loop through the rest of the array to create nodes and link them
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with the current element and link it to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Link the previous node to the current one
        prev = prev->next; // Move the prev pointer to the current node
    }
    return head; // Return the head of the doubly linked list
}

// Function to delete the head node
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // If the list is empty or has only one node, return nullptr
    }
    Node* prev = head;
    head = head->next; // Move the head to the next node
    head->back = nullptr; // Remove the backward link to the old head
    prev->next = nullptr; // Remove the forward link from the old head
    delete prev; // Delete the old head
    return head;
}

// Function to delete the tail node
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // If the list is empty or has only one node, return nullptr
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // Move to the last node
    }
    Node* prev = temp->back; // Get the previous node
    prev->next = nullptr; // Remove the forward link to the tail
    temp->back = nullptr; // Remove the backward link from the tail
    delete temp; // Delete the tail
    return head;
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

// Function to delete the kth element in the list
Node* deleteKthElement(Node* head, int k) {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        if (count == k) break; // Stop when the kth element is reached
        temp = temp->next;
    }

    Node* prev = temp->back; // Get the previous node
    Node* front = temp->next; // Get the next node

    if (prev == nullptr && front == nullptr) { // If it's the only node
        return nullptr;
    } else if (prev == nullptr) { // If it's the head node
        return deleteHead(head);
    } else if (front == nullptr) { // If it's the tail node
        return deleteTail(head);
    }

    // Link the previous and next nodes to bypass the current node
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp; // Delete the kth node

    return head;
}

// Function to delete a specific node given a pointer to it
void deleteNode(Node* temp) {
    Node* prev = temp->back; // Get the previous node
    Node* front = temp->next; // Get the next node

    if (front == nullptr) { // If it's the last node
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    // Link the previous and next nodes to bypass the current node
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp; // Delete the node
}


int main() {
    // Initialize a vector with elements
    vector<int> arr = {3, 2, 5, 4, 6};

    // Convert the array into a doubly linked list
    Node* head = ConvertArrayToDoublyLinklist(arr);

    // Example usage of delete functions
    // head = deleteHead(head); // Uncomment to delete the head
    // head = deleteTail(head); // Uncomment to delete the tail
    // head = deleteKthElement(head, 5); // Uncomment to delete the 5th element
    deleteNode(head->next); // Delete the second node

    // Display the final list
    display(head);

    return 0;
}
