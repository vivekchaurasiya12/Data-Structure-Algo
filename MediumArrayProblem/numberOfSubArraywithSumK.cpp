#include <bits/stdc++.h>
using namespace std;

// Function to find the number of subarrays with sum equal to k
int numberOfSubArray(vector<int> &arr, int k) {
    int n = arr.size();  // Get the size of the array
    int count = 0;       // Initialize the count of subarrays with sum k

    // Outer loop to start subarray from each index 'i'
    for (int i = 0; i < n; i++) {
        int sum = 0;  // Initialize sum of the subarray starting from 'i'

        // Inner loop to extend subarray from 'i' to 'j'
        for (int j = i; j < n; j++) {
            sum += arr[j];  // Add the current element to the sum

            // Check if the sum of the subarray equals k
            if (sum == k) {
                count++;  // If sum equals k, increment the count
            }
        }
    }

    // Return the total count of subarrays with sum equal to k
    return count;
}

int main() {
    int n, k;

    // Input the number of elements in the array and the target sum k
    cin >> n >> k;

    vector<int> arr(n);  // Initialize an array of size 'n'

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input each element into the array
    }

    // Call the function to find the number of subarrays with sum equal to k
    int num = numberOfSubArray(arr, k);

    // Output the result
    cout << num << " ";  // Print the number of subarrays with sum equal to k

    return 0;
}
