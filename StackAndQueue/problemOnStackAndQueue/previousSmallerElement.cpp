#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    stack<int> st; // Stack to keep track of elements for which previous smaller is not yet found
    vector<int> temp(A.size()); // Result vector to store previous smaller elements

    // Iterate over each element in the input array
    for (int i = 0; i < A.size(); i++) {
        // Pop elements from the stack that are greater than or equal to the current element
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        // If the stack is empty, no previous smaller element exists for A[i]
        if (st.empty()) {
            temp[i] = -1;
        } else {
            // Otherwise, the top of the stack is the previous smaller element
            temp[i] = st.top();
        }

        // Push the current element onto the stack for future comparisons
        st.push(A[i]);
    }

    return temp; // Return the result vector
}

int main() {
    // Input array
    vector<int> arr = {4, 5, 2, 10, 8};

    // Call the prevSmaller function
    vector<int> result = prevSmaller(arr);

    // Print the result
    cout << "Previous Smaller Elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
