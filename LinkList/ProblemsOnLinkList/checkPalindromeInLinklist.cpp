#include <bits/stdc++.h>
using namespace std;

// Define a structure for Node
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
        mover = mover->next;            // Move the pointer to the new end of the list
    }
    return head; // Return the head of the created linked list
}

// Function to display the contents of the linked list
void display(Node* head) {
    Node* temp = head; // Start from the head node
    while (temp != NULL) { // Traverse each node until reaching the end (NULL)
        cout << temp->data << " "; // Print data of the current node
        temp = temp->next;         // Move to the next node
    }
}
// Function to reverse a linked list from a given head node
Node* reverseLinklist(Node* head) {
    Node* temp = head;      // Initialize temp to traverse the list
    Node* prev = NULL;      // Previous pointer for reversing links

    // Traverse the linked list and reverse pointers
    while (temp != NULL) {
        Node* front = temp->next; // Save the next node
        temp->next = prev;        // Reverse the link
        prev = temp;              // Move prev to the current node
        temp = front;             // Move temp to the next node
    }
    return prev; // Return the new head of the reversed list
}

// Function to check if a linked list is a palindrome
bool checkPalindrome(Node* head) {
    Node* fast = head;   // Fast pointer moves two steps at a time
    Node* slow = head;   // Slow pointer moves one step at a time

    // Find the middle of the list (slow will be at the midpoint)
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list starting from slow->next
    Node* newHead = reverseLinklist(slow->next);

    // Initialize pointers to compare both halves
    Node* first = head;
    Node* second = newHead;

    // Compare the first half with the reversed second half
    while (second != NULL) {
        if (first->data != second->data) { // Mismatch found
            reverseLinklist(newHead); // Restore the list's original order
            return false; // List is not a palindrome
        }
        first = first->next;  // Move to the next node in the first half
        second = second->next; // Move to the next node in the second half
    }

    // Restore the original order of the second half
    reverseLinklist(newHead);
    return true; // List is a palindrome
}

// Main function
int main() {
    vector<int> arr = {1,2,1}; // Input array to be converted to linked list
    Node* head = convertArrayToLinklist(arr); 
    bool isPalindrome = checkPalindrome(head);      
    cout<<isPalindrome;
    //display(head);                           
    return 0;
}
