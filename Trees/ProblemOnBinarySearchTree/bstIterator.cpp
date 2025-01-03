#include <iostream>
#include <stack>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Define the BSTIterator class
class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    // Constructor to initialize the iterator with the root of the BST
    BSTIterator(TreeNode* root) {
        pushALL(root);
    }

    // Function to get the next smallest element in the BST
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        pushALL(tempNode->right);
        return tempNode->val;
    }

    // Function to check if there are more elements in the BST
    bool hasNext() {
        return !st.empty();
    }

private:
    // Helper function to push all left children of a node onto the stack
    void pushALL(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
};

// Main function to test the BSTIterator
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Initialize the BSTIterator
    BSTIterator iterator(root);

    // Test the iterator
    cout << "BST elements in sorted order: ";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}
