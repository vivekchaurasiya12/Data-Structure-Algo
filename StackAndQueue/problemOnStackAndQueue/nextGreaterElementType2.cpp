#include <bits/stdc++.h>
using namespace std;

// Function to find the Next Greater Elements in a circular array
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> temp(n); // Result array

    // Traverse the array in reverse order, twice the size for circular traversal
    for (int i = 2 * n - 1; i >= 0; i--) {
        // Remove elements from the stack that are <= current element
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }

        // If within bounds of the original array, update the result array
        if (i < n) {
            if (st.empty()) 
                temp[i] = -1; // No greater element
            else 
                temp[i] = st.top(); // NGE is the top of the stack
        }

        // Push the current element onto the stack
        st.push(nums[i % n]);
    }

    return temp;
}

int main() {
    vector<int> arr = {2, 5, 1, 2, 13, 4, 5};
    
    // Get the Next Greater Elements
    vector<int> newArray = nextGreaterElements(arr);
    
    // Print the result
    for (int i = 0; i < newArray.size(); i++) {
        cout << newArray[i] << " ";
    }

    return 0;
}
