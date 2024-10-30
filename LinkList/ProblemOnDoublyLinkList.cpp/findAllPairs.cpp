#include <bits/stdc++.h> // Including all standard libraries for convenience
using namespace std;

// Define the structure of a Node in the doubly linked list
struct Node {
public:
    int data;      // Data value of the node
    Node* next;    // Pointer to the next node
    Node* back;    // Pointer to the previous node

    // Constructor with parameters for data, next, and back pointers
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor to initialize only data, with next and back set to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array into a doubly linked list
Node* convertArrayToLinkList(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Track previous node for linking

    // Loop through the rest of the array to create nodes
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with the current element, linking it to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Link the previous node to the new one
        prev = temp;        // Move the previous pointer to the new node
    }
    return head; // Return the head of the doubly linked list
}

// Function to find the tail (last node) of the doubly linked list
Node* findTail(Node* head) {
    Node* tail = head;
    // Traverse the list until reaching the last node
    while (tail->next != NULL) {
        tail = tail->next;
    }
    return tail; // Return the last node
}

// Function to find pairs in the doubly linked list that sum up to a specified value
vector<pair<int, int>> findPair(Node* head, int sum) {
    // Edge case: If list is empty or has only one element, no pairs can be found
    vector<pair<int, int>> ans; 
    if(head == NULL || head->next == NULL) {
        return ans;
    }

    Node* left = head;              // Pointer to the start of the list
    Node* right = findTail(head);   // Pointer to the end of the list

    // Loop until left and right pointers cross or become equal
    while (left != right && left->data < right->data) {
        int currentSum = left->data + right->data;
        
        if (currentSum == sum) {     // Pair found with the desired sum
            ans.push_back({left->data, right->data}); // Add pair to the result list
            left = left->next;       // Move left pointer forward
            right = right->back;     // Move right pointer backward
        } 
        else if (currentSum < sum) 
        {
            left = left->next;       // Move left forward if sum is too small
        } 
        else {
            right = right->back;     // Move right backward if sum is too large
        }
    }
    return ans; // Return list of pairs
}


// Main function to test the doubly linked list operations
int main() {
    vector<int> arr = {1, 2, 3, 3, 4, 5, 8, 9}; // Array to convert into a doubly linked list

    Node* head = convertArrayToLinkList(arr); // Convert array to doubly linked list
    vector<pair<int, int>> ans = findPair(head, 5); // Find pairs with sum equal to 5

    // Loop through each pair and print it
    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }

    return 0; // End of program
}
