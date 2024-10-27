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
    Node* head = new Node(arr[0]); // Initialize the head node with the first element of the array
    Node* mover = head; // Pointer to traverse and link new nodes

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node for each element
        mover->next = temp; // Link the new node to the list
        mover = mover->next; // Move to the new end of the list
    }
    return head; // Return the head of the newly created linked list
}

void display(Node* head) {
    Node* temp = head; // Start from the head node
    while (temp != NULL) { // Traverse each node
        cout << temp->data << " "; // Print data of the current node
        temp = temp->next; // Move to the next node
    }
}

Node* removeNthNodeFromBack(Node* head, int N) {
    Node* fast = head; // Fast pointer to move N steps ahead
    Node* slow = head; // Slow pointer will lag behind

    // Move the fast pointer N steps ahead
    for (int i = 0; i < N; i++) {
        fast = fast->next;
    }

    // If fast reaches the end, we need to remove the head node
    if (fast == NULL) {
        return head->next;
    }

    // Move both fast and slow pointers until fast reaches the last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the N-th node from the end by adjusting pointers
    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete; // Free memory for removed node

    return head; // Return the modified list's head
}

int main() {
    vector<int> arr = {3, 1, 6, 8, 9, 2}; // Input array
    Node* head = convertArrayToLinklist(arr); // Convert array to linked list
    head = removeNthNodeFromBack(head, 1); // Remove the 1st node from the end
    display(head); // Display modified linked list

    return 0;
}
