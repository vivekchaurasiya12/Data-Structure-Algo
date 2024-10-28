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
bool checkPalindrome(Node* head){
     Node* temp = head;
     stack<int> st;
     while(temp!=NULL){
        st.push(temp->data);
        temp= temp->next;
     }
     temp = head;
     while(temp!=NULL){
        if(temp->data != st.top()){
             return false;
        }
        temp = temp->next;
        st.pop();
     }
     return true;
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
