#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node* next;

public:
    // Constructor to initialize both data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor to initialize data only; next pointer defaults to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToLinklist(vector<int> &arr) {
    Node* head = new Node(arr[0]); // Initialize the head node with the first element of the array.
    Node* mover = head; // Pointer to traverse and link new nodes.

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node for each element.
        mover->next = temp; // Link the new node to the list.
        mover = mover->next; // Move to the new end of the list.
    }
    return head; // Return the head of the newly created linked list.
}

void display(Node* head) {
    Node* temp = head; // Start from the head node.
    while (temp != NULL) { // Traverse each node.
        cout << temp->data << " "; // Print data of the current node.
        temp = temp->next; // Move to the next node.
    }
}

Node* sortLinklist(Node* head) {
    // Create dummy nodes to form three lists: zero, one, two
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);

    Node* zero = zerohead;
    Node* one = onehead;
    Node* two = twohead;
    Node* temp = head;

    // Traverse original list and partition nodes based on their values
    while (temp != NULL) {
        if (temp->data == 0) { // If the node value is 0
            zero->next = temp; // Append to the zero list
            zero = zero->next; // Move zero pointer forward
        }
        else if (temp->data == 1) { // If the node value is 1
            one->next = temp; // Append to the one list
            one = one->next; // Move one pointer forward
        }
        else { // If the node value is 2
            two->next = temp; // Append to the two list
            two = two->next; // Move two pointer forward
        }
        temp = temp->next; // Move to the next node in the original list
    }

    // Connect the three lists: zero -> one -> two
    zero->next = (onehead->next) ? (onehead->next) : (twohead->next); // Link zero list to one or two list
    one->next = twohead->next; // Link one list to two list
    two->next = NULL; // End of sorted list

    Node* newhead = zerohead->next; // Set the new head
    delete onehead; // Clean up dummy nodes
    delete zerohead;
    delete twohead;

    return newhead;
}

int main() {
    vector<int> arr = {1, 0, 2, 0, 1, 1, 2, 1, 0, 0, 2}; // Input array
    Node* head = convertArrayToLinklist(arr); // Convert array to linked list
    head = sortLinklist(head); // Sort the linked list
    display(head); // Display sorted linked list

    return 0;
}
