#include<bits/stdc++.h>
using namespace std;

// Structure to represent a node in the binary tree
struct Node{
    int data;             // Data stored in the node
    Node* left;           // Pointer to the left child
    Node* right;          // Pointer to the right child

    // Constructor to initialize a node with given value and set child pointers to null
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Class to calculate the diameter of the binary tree
class Diameter {
    public:
        // Function to calculate the height of the tree and update the diameter
        int findheight(Node* root, int &diameter) {
            if(root == NULL) return 0;  // Base case: Null node has height 0

            // Recursively calculate the height of the left and right subtrees
            int leftheight = findheight(root->left, diameter);
            int rightheight = findheight(root->right, diameter);

            // Update the diameter with the maximum value of left + right heights
            diameter = max(diameter, leftheight + rightheight);

            // Return the height of the current subtree
            return 1 + max(leftheight, rightheight);
        }

        // Function to find the diameter of the tree
        int findDiameter(Node* root) {
            int diameter = 0;               // Local variable to store the diameter
            findheight(root, diameter);     // Calculate the height and update diameter
            return diameter;                // Return the final diameter value
        }
};

int main(){
    // Creating a sample binary tree
    Node* root = new Node(1);               // Root node
    root->left = new Node(2);               // Left child of root
    root->right = new Node(3);              // Right child of root
    root->left->left = new Node(4);         // Left child of node 2
    root->left->right = new Node(5);        // Right child of node 2
    root->right->left = new Node(6);        // Left child of node 3
    root->right->right = new Node(7);       // Right child of node 3
    root->right->right->right = new Node(9);// Right child of node 7

    Diameter diameter;                      // Create an object of the Diameter class
    cout << diameter.findDiameter(root);    // Output the diameter of the tree
    return 0;
}
