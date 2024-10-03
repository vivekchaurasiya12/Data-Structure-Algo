#include <bits/stdc++.h>
using namespace std;

// Function to check if there exist two numbers in the array whose sum equals the target
string twoSum(vector<int> &arr, int n, int target) {
    map<int, int> mpp; // To store the number and its index

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        int a = arr[i]; // Current number
        int req = target - a; // The number we need to reach the target

        // Check if the required number is already in the map
        if (mpp.find(req) != mpp.end()) {
            return "Yes"; // Return "Yes" if a pair is found
        }

        // Store the current number and its index in the map
        mpp[a] = i;
    }
    
    return "No"; // Return "No" if no pair is found
}

int main() {
    int n, target;
    
    // Input array size and target value
    cin >> n >> target;
    
    vector<int> arr(n);
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the function and store the result
    string result = twoSum(arr, n, target);
    
    // Output the result
    cout << result;
    
    return 0;
}
