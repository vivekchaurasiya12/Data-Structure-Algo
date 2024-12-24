#include<bits/stdc++.h>
using namespace std;

// Definition of the Node structure for a binary tree.
struct Node{
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value and set children to null.
    Node(int val):data(val),left(nullptr),right(nullptr) {}
};

class Solution{
    public:
    // Helper function to calculate the maximum path sum for a given subtree.
    int maxPathDown(Node* root, int& maxi){
        if(root == NULL) return 0; // Base case: if the node is null, return 0.

        // Recursively calculate the maximum path sum for the left and right subtrees.
        // Use max(0, ...) to ignore negative paths (don't include in the sum).
        int leftsum = max(0, maxPathDown(root->left, maxi));
        int rightsum = max(0, maxPathDown(root->right, maxi));

        // Update the overall maximum path sum (maxi) considering the current node.
        maxi = max(maxi, leftsum + rightsum + root->data);

        // Return the maximum path sum including the current node and one of its subtrees.
        return root->data + max(leftsum, rightsum);
    }

    // Main function to calculate the maximum path sum in the binary tree.
    int maxPathSum(Node* root){
        int maxi = INT_MIN; // Initialize the maximum sum as the smallest possible integer.
        maxPathDown(root, maxi); // Call the helper function to compute the maximum path sum.
        return maxi; // Return the overall maximum path sum.
    }
};

int main(){
    // Create a sample binary tree.
    Node* root = new Node(1);               // Root node
    root->left = new Node(2);               // Left child of root
    root->right = new Node(3);              // Right child of root
    root->left->left = new Node(4);         // Left child of node 2
    root->left->right = new Node(5);        // Right child of node 2
    root->right->left = new Node(6);        // Left child of node 3
    root->right->right = new Node(7);       // Right child of node 3
    root->right->right->right = new Node(9);// Right child of node 7

    // Create a Solution object and calculate the maximum path sum.
    Solution solution;
    cout << solution.maxPathSum(root) << endl; // Print the result.

    return 0;
}
