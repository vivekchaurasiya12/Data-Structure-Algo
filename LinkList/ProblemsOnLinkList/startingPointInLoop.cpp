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

// Function to convert a vector into a linked list and create a cycle
Node* convertArrayToLinklist(vector<int> &arr) {
    Node* head = new Node(arr[0]); // Initialize head with first element
    Node* mover = head;  // Pointer to traverse and add nodes

    // Loop through the vector starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create new node for each element
        mover->next = temp;            // Link new node to the list
        mover = mover->next;           // Move to new end of the list
    }

    // Creating a cycle by linking last node to the third node (head->next->next)
    mover->next = head->next->next;

    return head; // Return head of created linked list
}

// Function to display circular linked list starting from a given node
void display(Node* head) {
    Node* temp = head; // Start from head node
    cout << temp->data << " ";
    temp = temp->next;

    while (temp != head) { // Traverse each node until reaching start point
        cout << temp->data << " "; // Print current node’s data
        temp = temp->next;         // Move to the next node
    }
}

// Function to find the starting point of the loop in the linked list
Node* startingPointInLoop(Node* head) {
    if(head==NULL && head->next==NULL) return NULL;
    Node* slow = head;
    Node* fast = head;

    // Detect cycle using Floyd’s cycle-finding algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            slow = head; // Move slow to head

            // Move both slow and fast one node at a time to find loop start
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Return loop starting node
        }
    }
    return NULL; // No cycle found
}

int main() {
    vector<int> arr = {1, 5, 4, 2, 4, 6, 0, 8, 8}; // Array to convert into linked list

    // Convert array to linked list with a cycle
    Node* head = convertArrayToLinklist(arr);

    // Find starting point of the loop
    head = startingPointInLoop(head);

    // Display the circular linked list starting from the loop's starting node
    display(head);

    return 0;
}
