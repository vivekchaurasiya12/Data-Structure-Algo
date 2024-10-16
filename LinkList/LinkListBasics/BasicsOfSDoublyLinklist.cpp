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

int main() {
    // Initialize a vector with elements
    vector<int> arr = {3, 2, 5, 4, 6};

    // Convert the array into a doubly linked list
    Node* head = ConvertArrayToDoublyLinklist(arr);

    // Traverse the doubly linked list and print the elements
    Node* temp = head;
    int count = 0; // To count the length of the list
    while (temp != NULL) {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next; // Move to the next node
        count++; // Increment the counter
    }
    cout << endl;

    // Print the length of the doubly linked list
    cout << "Length of doubly linked list: " << count << endl;

    return 0; 
}
