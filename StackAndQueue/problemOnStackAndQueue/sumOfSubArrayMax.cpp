#include <bits/stdc++.h>
using namespace std;


// Function to find the Next Greater Element Equal (NGEE) for each element in the array.
vector<int> findNGEE(vector<int>& nums) {
    int n = nums.size();
    vector<int> ngee(n); // Array to store indices of the Next Greater Element Equal
    stack<int> st; // Stack to maintain indices
    for (int i = n - 1; i >= 0; i--) { // Traverse from right to left
        // Pop elements from the stack until a greater element is found
        while (!st.empty() && nums[st.top()] < nums[i])
            st.pop();
        ngee[i] = st.empty() ? n : st.top(); // If stack is empty, set NGEE to n
        st.push(i); // Push current index onto the stack
    }
    return ngee;
}

// Function to find the Previous Greater Element (PGE) for each element in the array.
vector<int> findPGE(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n); // Array to store indices of the Previous Greater Element
    stack<int> st; // Stack to maintain indices
    for (int i = 0; i < n; i++) { // Traverse from left to right
        // Pop elements from the stack until a greater element is found
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        pge[i] = st.empty() ? -1 : st.top(); // If stack is empty, set PGE to -1
        st.push(i); // Push current index onto the stack
    }
    return pge;
}

// Function to calculate the sum of the maximum elements in all subarrays.
long long sumSubarrayMax(vector<int>& nums) {
    vector<int> ngee = findNGEE(nums); // Get indices of the Next Greater Element Equal
    vector<int> pge = findPGE(nums); // Get indices of the Previous Greater Element

    long long total = 0;
    for (int i = 0; i < nums.size(); i++) {
        // Number of subarrays where nums[i] is the maximum element
        int left = i - pge[i]; // Number of subarrays to the left
        int right = ngee[i] - i; // Number of subarrays to the right

        total += right * left * 1LL * nums[i]; // Contribution of nums[i]
    }
    return total;
}



int main() {
    vector<int> nums = {1,4,3,2};
    cout << "Subarray Ranges Sum: " << sumSubarrayMax(nums) << endl; // Output the result
    return 0;
}
