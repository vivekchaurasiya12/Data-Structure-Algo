#include<bits/stdc++.h>
using namespace std;

int findMaximumConsecutiveOnes(vector<int>& arr) {
    int maxi = 0;  // Stores the maximum count of consecutive 1's
    int count = 0; // Tracks the current count of consecutive 1's

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;                // Increment count if 1 is encountered
            maxi = max(maxi, count); // Update maxi if count is larger
        } else {
            count = 0; // Reset count when 0 is encountered
        }
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;  // Input size of the array
    vector<int> arr(n); // Declare array of size n

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and print the maximum consecutive ones
    int num = findMaximumConsecutiveOnes(arr);
    cout << num << endl;

    return 0;
}
