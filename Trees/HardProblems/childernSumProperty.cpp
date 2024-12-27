#include<bits/stdc++.h>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to modify the tree to follow the Children Sum Property
Node* changeTree(Node*& root) {
    // Base case: If the root is null, return null
    if (root == NULL) return root;

    int child = 0;

    // Calculate the sum of left and right child values
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    // If the sum of children is greater than or equal to root's data
    // update the root's data
    if (child >= root->data) root->data = child;
    else {
        // Otherwise, propagate the root's data to its children
        if (root->left) root->left->data = root->data;
        else if (root->right) root->right->data = root->data;
    }

    // Recursively call the function for left and right subtrees
    changeTree(root->left);
    changeTree(root->right);

    // Update the root's data to be the sum of its children's data
    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;
    if (root->left || root->right) root->data = total;

    return root;
}

// Function to check if the tree follows the Children Sum Property
bool checkSum(Node* root) {
    // Base case: If the root is null or it's a leaf node, return true
    if (root == NULL || (root->left == NULL && root->right == NULL)) return true;

    int child = 0;

    // Calculate the sum of left and right child values
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    // If the current node's data is not equal to the sum of its children, return false
    if (child != root->data) {
        return false;
    }

    // Recursively check for left and right subtrees
    return checkSum(root->left) && checkSum(root->right);
}

int main() {
    // Creating a sample tree
    /*
                40
               /  \
             20    10
            / \    / \
           2   5  3   8
    */
    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->right->right = new Node(8);

    // Check if the tree follows the Children Sum Property
    if (checkSum(root)) {
        cout << "Follows Children Sum Property" << endl;
    } else {
        cout << "Does Not Follow Children Sum Property" << endl;
    }

    // Modify the tree to follow the Children Sum Property
    changeTree(root);

    // Check again if the tree now follows the Children Sum Property
    if (checkSum(root)) {
        cout << "Follows Children Sum Property" << endl;
    } else {
        cout << "Does Not Follow Children Sum Property" << endl;
    }

    return 0;
}
