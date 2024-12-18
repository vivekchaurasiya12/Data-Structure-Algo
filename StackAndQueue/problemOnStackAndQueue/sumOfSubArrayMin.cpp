#include <bits/stdc++.h>
using namespace std;

// Function to find the Next Smaller Element (NSE) for each element in the array.
vector<int> findNSE(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n); // Array to store indices of the Next Smaller Element
    stack<int> st; // Stack to maintain indices
    for(int i = n - 1; i >= 0; i--) { // Traverse from right to left
        // Pop elements from the stack until a smaller element is found
        while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();
        nse[i] = st.empty() ? n : st.top(); // If stack is empty, set NSE to n
        st.push(i); // Push current index onto the stack
    }
    return nse;
}

// Function to find the Previous Smaller Element Equal (PSEE) for each element in the array.
vector<int> findPSEE(vector<int>& nums) {
    int n = nums.size();
    vector<int> psee(n); // Array to store indices of the Previous Smaller Element Equal
    stack<int> st; // Stack to maintain indices
    for(int i = 0; i < n; i++) { // Traverse from left to right
        // Pop elements from the stack until a smaller element is found
        while(!st.empty() && nums[st.top()] > nums[i])
            st.pop();
        psee[i] = st.empty() ? -1 : st.top(); // If stack is empty, set PSEE to -1
        st.push(i); // Push current index onto the stack
    }
    return psee;
}

// Function to calculate the sum of the minimum elements in all subarrays.
long long sumSubarrayMins(vector<int>& nums) {
    vector<int> nse = findNSE(nums); // Get indices of the Next Smaller Element
    vector<int> psee = findPSEE(nums); // Get indices of the Previous Smaller Element Equal

    long long total = 0;
    for(int i = 0; i < nums.size(); i++) {
        // Number of subarrays where nums[i] is the minimum element
        int left = i - psee[i]; // Number of subarrays to the left
        int right = nse[i] - i; // Number of subarrays to the right

        total += right * left * 1LL * nums[i]; // Contribution of nums[i]
    }
    return total;
}


int main() {
    vector<int> nums = {4, 1, 2, 3};
    cout << "Subarray Ranges Sum: " << sumSubarrayMins(nums) << endl; // Output the result
    return 0;
}
