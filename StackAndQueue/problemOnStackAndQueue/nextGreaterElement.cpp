#include <bits/stdc++.h>
using namespace std;

// Function to find Next Greater Elements for the array
vector<int> nextGreaterElement(vector<int> &arr) {
    stack<int> st; // Stack to store elements
    vector<int> temp(arr.size()); // Result vector
    
    // Traverse the array from right to left
    for (int i = arr.size() - 1; i >= 0; i--) {
        // Remove elements from the stack that are <= current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        
        // If the stack is empty, no greater element exists
        if (st.empty()) 
            temp[i] = -1;
        else 
            temp[i] = st.top(); // The top of the stack is the NGE
        
        // Push the current element onto the stack
        st.push(arr[i]);
    }
    
    return temp;
}

int main() {
    // Input array
    vector<int> arr = {2, 3, 1, 4, 5, 1, 2, 3, 2, 1, 6, 7, 9, 8, 4, 5};
    
    // Get the Next Greater Elements
    vector<int> newArray = nextGreaterElement(arr);
    
    // Print the result
    for (int i = 0; i < newArray.size(); i++) {
        cout << newArray[i] << " ";
    }
    
    return 0;
}
