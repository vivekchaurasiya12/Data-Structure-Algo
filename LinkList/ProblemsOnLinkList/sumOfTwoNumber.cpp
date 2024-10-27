#include <bits/stdc++.h> // Including all standard libraries
using namespace std;

// Structure for each node in the linked list
struct Node {
public:
    int data;   // Data held by the node
    Node* next; // Pointer to the next node

    // Constructor to initialize data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor to initialize data and set next pointer to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node* convertArray(vector<int> arr) {
    Node* head = new Node(arr[0]); // Initialize the head node
    Node* mover = head; // Pointer to traverse and build the list
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node for each element
        mover->next = temp; // Link the new node
        mover = mover->next; // Move to the next node
    }
    return head;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head; // Temporary pointer for traversal
    while (temp) { // Loop until end of list
        cout << temp->data << " "; // Print data of each node
        temp = temp->next; // Move to the next node
    }
}

// Function to add two numbers represented by linked lists
Node* sumOfTwoNumber(Node* head1, Node* head2) {
    Node* dummyHead = new Node(-1); // Dummy head for result list
    Node* curr = dummyHead; // Current pointer for result list
    int carry = 0; // Initialize carry to 0

    // Temporary pointers to traverse both lists
    Node* temp1 = head1;
    Node* temp2 = head2;

    // Loop until both lists are fully traversed
    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry; // Start with carry for current position
        if (temp1) sum += temp1->data; // Add data from first list if available
        if (temp2) sum += temp2->data; // Add data from second list if available

        Node* newNode = new Node(sum % 10); // Create node for the sum's last digit
        carry = sum / 10; // Update carry for next position
        curr->next = newNode; // Append the new node to the result
        curr = curr->next; // Move to the next node in result list

        // Move to the next nodes in input lists
        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
    }

    // If carry is left after loop, add it as a new node
    if (carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummyHead->next; // Return head of the result list, skipping dummy head
}

int main() {
    vector<int> arr1 = {3, 4, 5, 8}; // First number in reverse order as linked list
    vector<int> arr2 = {9, 2, 4, 5}; // Second number in reverse order as linked list

    Node* head1 = convertArray(arr1); // Convert first array to linked list
    Node* head2 = convertArray(arr2); // Convert second array to linked list

    Node* head = sumOfTwoNumber(head1, head2); // Get sum of the two lists
    print(head); // Print the result list
   
    return 0;
}
