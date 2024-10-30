#include <bits/stdc++.h>
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
    // Initialize the head with the first element in the array
    Node* head = new Node(arr[0]);
    Node* mover = head;  // Pointer to traverse and add nodes

    // Loop through the vector starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node for each element in the array
        mover->next = temp;            // Link the new node to the list
        mover = mover->next;           // Move the pointer to the new end of the list
    }

    // Creating a cycle by linking the last node to the third node (head->next->next)
    mover->next = head->next->next;

    return head; // Return the head of the created linked list
}

// Helper function to find the length of a loop in the linked list
int findLength(Node* slow, Node* fast) {
    int count = 1;          // Start with a count of 1 for the initial node
    slow = slow->next;      // Move to the next node

    // Traverse the loop until reaching the start node again
    while (slow != fast) {
        count++;            // Increment count for each unique node in the cycle
        slow = slow->next;  // Move to the next node in the loop
    }
    return count;           // Return the total count (loop length)
}

// Function to detect the loop and find its length in a linked list
int lengthofLoop(Node* head) {
    Node* slow = head;      // Slow pointer starts at the head
    Node* fast = head;      // Fast pointer also starts at the head

    // Loop until fast and fast->next are not NULL
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow pointer one step
        fast = fast->next->next;   // Move fast pointer two steps

        // If slow and fast pointers meet, a loop exists
        if (slow == fast) {
            return findLength(slow, fast); // Calculate the loop's length
        }
    }
    return 0; // Return 0 if no loop is detected
}

int main() {
    vector<int> arr = {1, 5, 4, 2, 4, 6, 0, 8, 8}; // Initialize the array to convert into a linked list

    // Convert the array to a linked list
    Node* head = convertArrayToLinklist(arr);

    // Find the length of the loop in the linked list
    int length = lengthofLoop(head);

    // Display the length of the loop (0 if no loop exists)
    cout << "Length of loop: " << length << endl;

    return 0;
}
