#include<bits/stdc++.h>  // Includes standard libraries
using namespace std;

struct Node {
    public:
    int data;     // Stores the value in the node
    Node* next;   // Pointer to the next node in the linked list

    // Constructor 1: Initializes node with data and pointer to the next node
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor 2: Initializes node with data and sets the next pointer to nullptr
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array into a linked list
Node* converArrayToLinklist(vector<int> &arr) {
    // Initialize head of the linked list with the first element of the array
    Node* head = new Node(arr[0]);  
    Node* mover = head;  // Pointer to traverse the linked list
    
    // Loop through the rest of the array to create nodes and link them
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);  // Create new node with array element
        mover->next = temp;  // Link current node to the next node
        mover = temp;  // Move to the next node
    }
    return head;  // Return the head of the linked list
}

// Function to print the linked list
void print(Node* head){
    // Traverse and print each node's data until reaching the end (NULL)
    while(head != NULL){
        cout << head->data << " ";  // Print the data of the current node
        head = head->next;  // Move to the next node
    }
    cout << endl;
}

// Function to insert a node at the head of the linked list
Node* insertAtHead(Node* head, int value) {
    Node* temp = new Node(value, head);  // Create new node with value and point it to the current head
    return temp;  // Return new head
}

// Function to insert a node at the tail of the linked list
Node* insertAtTail(Node* head, int value) {
    if(head == NULL){
        return new Node(value);  // If list is empty, create new node as head
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;  // Traverse to the last node
    }
    Node* newNode = new Node(value);  // Create new node and link it at the end
    temp->next = newNode;  // Update the next pointer of the last node
    return head;  // Return the head
}

// Function to insert a node at the K-th position in the linked list
Node* insertAtKthPosition(Node* head, int value, int k) {
    if(head == NULL) {
       if(k == 1) return new Node(value);  // If list is empty and K is 1, create new node
       else return head;  // If K is not 1, return the unchanged list
    }
    if(k == 1) {
        Node* newHead = new Node(value, head);  // Insert new node as the new head
        return newHead;
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == (k - 1)){  // When at (K-1)-th position
            Node* x = new Node(value);  // Create new node
            x->next = temp->next;  // Link new node to the next node
            temp->next = x;  // Insert new node at K-th position
            break;
        }
        temp = temp->next;
    }
    return head;  // Return the updated head of the list
}

// Function to insert a node before the first occurrence of an element in the linked list
Node* insertBeforeElement(Node* head, int value, int el) {
    if(head == NULL) {
        return NULL;  // If list is empty, return NULL
    }
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->next->data == el) {  // When the next node has the element `el`
            Node* x = new Node(value);  // Create new node with value
            x->next = temp->next;  // Link new node before the node with element `el`
            temp->next = x;  // Update current node to point to the new node
            break;
        }
        temp = temp->next;
    }
    return head;  // Return the updated head of the list
}

int main() {
    int k;
    cin >> k;  // Input K for the position in linked list operations
    vector<int> arr = {62, 8, 2, 9, 4, 5, 3};  // Initialize array with values
    
    // Convert the array into a linked list and store the head
    Node* head = converArrayToLinklist(arr);
    
    // Uncomment one of the below functions to test different insert functionalities:

    // head = insertAtHead(head, 100);  // Insert 100 at the head
    // print(head);  // Print the modified linked list
    
    // head = insertAtTail(head, 100);  // Insert 100 at the tail
    // print(head);  // Print the modified linked list
    
    // head = insertAtKthPosition(head, 100, k);  // Insert 100 at the K-th position
    // print(head);  // Print the modified linked list
    
    head = insertBeforeElement(head, 100, 8);  // Insert 100 before element 8
    print(head);  // Print the modified linked list
    
    return 0;
}
