#include<bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with sum equal to 'k'
int longestSubArray(vector<int>& arr, int n, long long k) {
    map<long long, int> preSumMap;  // To store prefix sum and their first occurrence index
    long long sum = 0;              // Tracks the cumulative sum of elements
    int maxLen = 0;                 // Stores the length of the longest subarray with sum 'k'

    // Iterate over the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Add current element to cumulative sum

        // If the sum equals k, update maxLen to the length of the entire array up to this point
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Calculate the remaining sum that we need to find in the map
        long long rem = sum - k;

        // If the remaining sum exists in preSumMap, it means a subarray with sum 'k' is found
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];  // Length of the subarray with sum 'k'
            maxLen = max(maxLen, len);     // Update maxLen if this subarray is longer
        }

        // Store the first occurrence of the cumulative sum in the map
        // We only store it if it's not already present to maintain the longest subarray calculation
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    
    return maxLen;  // Return the length of the longest subarray with sum 'k'
}

int main() {
    int n;
    long long k;

    // Input number of elements and target sum 'k'
    cin >> n >> k;

    vector<int> arr(n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to get the length of the longest subarray
    int length = longestSubArray(arr, n, k);

    // Output the result
    cout << length << endl;

    return 0;
}
