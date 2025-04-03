#include<bits/stdc++.h>  // Includes standard libraries
using namespace std;

struct Node {
    public:
    int data;     // Stores the value in the node
    Node* next;   // Pointer to the next node in the linked list

    // Constructor 1: Initializes node with data and pointer to the next node
    public:
    
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor 2: Initializes node with data and sets the next pointer to nullptr
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array into a linked list
Node* convertArrayToLinklist(vector<int> &arr) {
    // Initialize head of the linked list with the first element of the array
    Node* head = new Node(arr[0]);  
    Node* mover = head;  // Pointer to traverse the linked list
    
    // Loop through the rest of the array to create nodes and link them
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);  // Create new node with array element
        mover->next = temp;  // Link current node to the next node
        mover = temp;  // Move to the next node
    }
    return head;  // Return the head of the linked list
}

// Function to find the length of the linked list
int lengthofLinkList(Node* head) {
    int count = 0;  // Initialize counter
    Node* temp = head;  // Temporary pointer to traverse the list
    
    // Traverse the linked list and count the nodes
    while(temp) {
        count++;  // Increment count for each node
        temp = temp->next;  // Move to the next node
    }
    return count;  // Return the total count
}

// Function to check if a value is present in the linked list
bool checkIfPresent(Node* head, int val) {
    Node* temp = head;  // Temporary pointer to traverse the list
    
    // Traverse the linked list
    while(temp) {
        if(temp->data == val) {  // If the current node's data matches the value
            return true;  // Return true if found
        }
        temp = temp->next;  // Move to the next node
    }
    return false;  // Return false if value is not found
}

int main() {
    vector<int> arr = {62, 4, 5, 3};  // Initialize array with values
    
    // Create a node with the 4th element of the array and print its memory address and data
    Node* y = new Node(arr[3]);
    cout << y << endl;  // Print the memory address of the node
    cout << y->data << endl;  // Print the data of the node (3)
    
    // Convert the array into a linked list and store the head
    Node* head = convertArrayToLinklist(arr);
    
    // Traverse the linked list and print the data of each node
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;  // Move to the next node
    }
    cout << endl;
    
    // Get the length of the linked list and print it
    int length = lengthofLinkList(head);
    cout << length << endl;  // Print the length
    
    // Check if the value 5 is present in the linked list and print the result
    bool num = checkIfPresent(head, 5);
    cout << num << endl;  // Print 1 if found, 0 if not
   
    return 0;
}
