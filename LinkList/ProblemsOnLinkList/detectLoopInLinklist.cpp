#include<bits/stdc++.h>
using namespace std;

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

    // Creating a cycle by linking the last node to the third node (head->next->next)
    mover->next = head->next->next;

    return head; // Return the head of the created linked list
}

// Function to detect a cycle in the linked list using Floyd’s Cycle-Finding Algorithm
bool detectCycle(Node* head) {
    if (head == NULL || head->next == NULL) return false; // Check for empty or single-node list (no cycle possible)

    Node* slow = head; // Slow pointer moves one step at a time
    Node* fast = head; // Fast pointer moves two steps at a time

    // Traverse the list with the two pointers until fast pointer reaches the end
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer by one step
        fast = fast->next->next;    // Move fast pointer by two steps

        if (slow == fast) {         // If slow and fast pointers meet, a cycle exists
            return true;
        }
    }

    return false; // If no cycle is found, return false
}

int main() {
    vector<int> arr = {1,5,4,2,4,6,0,8,5,3,8}; // Initialize the array to convert into a linked list

    // Convert the array to a linked list
    Node* head = convertArrayToLinklist(arr);

    // Detect if there's a cycle in the list
    bool type = detectCycle(head);

    // Print the result: '1' for cycle detected, '0' for no cycle
    cout << type << endl;

    return 0;
}
