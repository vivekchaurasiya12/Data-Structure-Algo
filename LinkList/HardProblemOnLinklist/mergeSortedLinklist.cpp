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
    // Initialize the head node with the first element in the vector
    Node* head = new Node(arr[0]);
    Node* mover = head;  // Pointer used to traverse and add new nodes to the list

    // Loop through the vector starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node for each element in the vector
        Node* temp = new Node(arr[i]);
        
        // Link the new node to the current end of the linked list
        mover->next = temp;
        
        // Move the pointer to the new end of the list
        mover = mover->next;
    }
    return head; // Return the head of the created linked list
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

// Function to merge two sorted linked lists into a single sorted linked list
Node* mergeLinklist(Node* head1, Node* head2) {
    // Initialize a dummy node to simplify the merging process
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;  // Pointer to keep track of the end of the merged list

    // Pointers to traverse the two linked lists
    Node* t1 = head1;
    Node* t2 = head2;
    
    // Traverse both lists, picking the smaller element from each
    while (t1 != NULL && t2 != NULL) {
        if (t1->data < t2->data) {
            temp->next = t1;  // Link to the node from the first list
            temp = t1;        // Move temp pointer to the end of the merged list
            t1 = t1->next;    // Move t1 to the next node in list 1
        } else {
            temp->next = t2;  // Link to the node from the second list
            temp = t2;        // Move temp pointer to the end of the merged list
            t2 = t2->next;    // Move t2 to the next node in list 2
        }
    }

    // Attach any remaining nodes from list 1 or list 2 (if one list is longer)
    if (t1) {
        temp->next = t1;
    }
    if (t2) {
        temp->next = t2;
    }

    // Return the head of the merged list, skipping the dummy node
    return dummyNode->next;
}


int main() {
    
    vector<int> arr1 = {1, 2, 4, 5, 7, 8, 10}; 
    vector<int> arr2 = {3, 5, 6, 9, 10};

    // Convert arrays to linked lists
    Node* head1 = convertArrayToLinklist(arr1);
    Node* head2 = convertArrayToLinklist(arr2);

    // Merge the two linked lists
    Node* head = mergeLinklist(head1, head2);

    
    display(head);

    return 0; 
}
