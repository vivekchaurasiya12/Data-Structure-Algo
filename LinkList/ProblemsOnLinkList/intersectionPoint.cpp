#include<bits/stdc++.h>
using namespace std;
struct Node{
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

Node* intersectionPoint(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* temp1 = head1;  // Initialize temp1 pointer to head1
    Node* temp2 = head2;  // Initialize temp2 pointer to head2

    // Traverse both lists until temp1 and temp2 meet at the intersection or end at NULL
    while (temp1 != temp2) {
        temp1 = temp1->next; // Move temp1 to the next node
        temp2 = temp2->next; // Move temp2 to the next node

        // If both pointers meet at NULL, no intersection exists
        if (temp1 == temp2) {
            return temp1;  // Intersection point found
        }
        
        // If temp1 reaches the end, reset it to head2 to align distances
        if (temp1 == NULL) {
            temp1 = head2;
        }

        // If temp2 reaches the end, reset it to head1 to align distances
        if (temp2 == NULL) {
            temp2 = head1;
        }
    }
    return temp1;  // Return intersection node or NULL if no intersection
}


int main(){
    vector<int> arr1 = {1,5,4}; 
    vector<int> arr2 = {4,2,7,8,4,9,3};       
    Node* head1= convertArrayToLinklist(arr1);
    Node* head2 = convertArrayToLinklist(arr2);
    
    // Creating an intersection point for testing purposes
    head2->next->next->next->next = head1->next->next;  // Intersect at node with data 4

    Node* intersection = intersectionPoint(head1, head2);  // Find the intersection point

    if (intersection) {
        cout << "Intersection Point Data: " << intersection->data << endl;  // Print intersection data
    } else {
        cout << "No intersection found." << endl;  // Print if no intersection
    }
                      
    return 0;
}
