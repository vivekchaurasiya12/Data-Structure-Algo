#include<bits/stdc++.h>
using namespace std;
struct Node{
   public:
    int data;
    Node* next;

   public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

   public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArraytoLinklist(vector<int> &arr) {
    Node* head = new Node(arr[0]); // Create the head node with the first element of the array.
    Node* mover = head; // Pointer to traverse and add new nodes.

    // Loop through the remaining elements and add each to the list.
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node.
        mover->next = temp; // Link the new node to the current list.
        mover = mover->next; // Move the pointer to the new last node.
    }
    return head; // Return the head of the linked list.
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* oddEvenLinklist(Node* head) {
    // If the list is too short, return the original list.
    if (!head || !head->next) return head;

    Node* odd = head;            // Pointer for odd-position nodes.
    Node* even = head->next;      // Pointer for even-position nodes.
    Node* evenhead = even;        // Store the head of even nodes to link later.

    // Rearrange nodes by connecting odd nodes to next odd and even nodes to next even.
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;  // Link current odd node to next odd-position node.
        odd = odd->next;         // Move odd pointer forward.
        even->next = odd->next;  // Link current even node to next even-position node.
        even = even->next;       // Move even pointer forward.
    }

    odd->next = evenhead; // Link the end of the odd list to the head of the even list.
    return head; // Return the new head of the rearranged list.
}
int main() {
    vector<int> arr = {2, 1, 5, 4, 7}; // Initialize an array to be converted to a linked list.
    Node* head = convertArraytoLinklist(arr); // Convert array to linked list.

    head = oddEvenLinklist(head); // Rearrange list by odd-even positions.
    display(head); // Display the rearranged linked list.

    return 0;
}
