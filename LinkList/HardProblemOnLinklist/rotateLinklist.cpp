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
        mover = mover->next;           // Move the pointer to the new end of the list
    }
    return head; // Return the head of the created linked list
}

// Function to find the tail node of a list segment for a given length 'k'
Node* findtail(Node* temp, int k) {
    // Move forward 'k-1' times to get to the k-th node
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }
    return temp; // Return the k-th node as the new tail
}

// Function to rotate the linked list by 'k' positions to the right
Node* rotateLinklist(Node* head, int k) {
      Node* tail = head; // Start from the head
      int len = 1;       // Initialize length counter

      // Calculate the length of the list and find the original tail
      while (tail->next != NULL) {
        len++;              // Increment length for each node
        tail = tail->next;  // Move to the next node
      }

      // If 'k' is a multiple of 'len', rotation is not needed
      if (k % len == 0) return head;

      k = k % len;           // Reduce 'k' to within the length of the list
      tail->next = head;     // Create a circular link by connecting tail to head

      // Find the new tail by moving 'len-k' steps from the head
      Node* newTail = findtail(head, len - k);
      head = newTail->next;  // Set the new head to be the node after newTail
      newTail->next = NULL;  // Break the circular link to finish rotation
      return head;           // Return the new head of the rotated list
}

// Function to display the contents of the linked list
void display(Node* head) {
    Node* temp = head; // Start from the head node
    while (temp != NULL) {      // Traverse each node until reaching the end (NULL)
        cout << temp->data << " "; // Print data of the current node
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a new line after displaying all nodes
}

// Main function
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Input array to be converted to linked list
    Node* head = convertArrayToLinklist(arr);          // Convert array to linked list
    
    int k = 3;                  // Number of positions to rotate the list by
    head = rotateLinklist(head, k); // Rotate the list by k positions
    display(head);               // Display the modified linked list
    
    return 0; // End of program
}
