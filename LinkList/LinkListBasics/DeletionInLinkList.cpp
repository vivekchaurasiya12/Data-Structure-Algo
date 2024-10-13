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

// Function to delete the head of the linked list
Node* deletionofLinklistOfHead(Node* head){
    if(head == NULL) return head;  // If the list is empty, return
    Node* temp = head;  // Temporary pointer to store the head node
    head = head->next;  // Move head to the next node
    delete temp;  // Delete the original head
    return head;  // Return the new head of the list
}

// Function to delete the tail of the linked list
Node* deletionofLinklistOfTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;  // If list is empty or has only one node, return NULL
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;  // Traverse to the second last node
    }
    delete temp->next;  // Delete the last node
    temp->next = nullptr;  // Set the new tail's next pointer to NULL
    return head;
}

// Function to delete the K-th node of the linked list
Node* deletionofLinklistatKth(Node* head, int k){
    if(head == NULL) return head;  // If list is empty, return
    if(k == 1){
        Node* temp = head;  // If the first node is to be deleted
        head = head->next;  // Move head to the next node
        free(temp);  // Free the memory of the first node
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){  // When we reach the K-th node
            prev->next = prev->next->next;  // Remove the node from the list
            free(temp);  // Free the memory of the K-th node
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;  // Return the modified head of the list
}

// Function to delete the first occurrence of an element from the linked list
Node* deleteElement(Node* head, int el){
    if(head == NULL) return head;  // If the list is empty, return
    if(head->data == el){
        Node* temp = head;  // If the element to delete is the head node
        head = head->next;  // Move head to the next node
        free(temp);  // Free the memory of the head node
        return head;
    }
   
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){  // When the node with the target element is found
            prev->next = prev->next->next;  // Remove the node from the list
            free(temp);  // Free the memory of the node
            break;
        }
        prev = temp;
        temp = temp->next;  // Move to the next node
    }
    return head;  // Return the modified head of the list
}

int main() {
    vector<int> arr = {62, 8, 2, 9, 4, 5, 3};  // Initialize array with values
    // Convert the array into a linked list and store the head
    Node* head = converArrayToLinklist(arr);
    
    // Uncomment the respective lines below to test different delete functions:

    // head = deletionofLinklistOfHead(head);  // Delete head node
    // print(head);  // Print the modified linked list
    
    // head = deletionofLinklistOfTail(head);  // Delete tail node
    // print(head);  // Print the modified linked list
    
    // head = deletionofLinklistatKth(head, 6);  // Delete the 6th node
    // print(head);  // Print the modified linked list
    
    head = deleteElement(head, 8);  // Delete the node with value 8
    print(head);  // Print the modified linked list
    
    return 0;
}
