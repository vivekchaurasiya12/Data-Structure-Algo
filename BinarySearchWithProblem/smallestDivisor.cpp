// Including all standard headers from the C++ library
#include<bits/stdc++.h>
using namespace std;

// Function to check if for a given divisor `mid`, the sum of the ceiling of array elements divided by `mid` is <= threshold
bool sum(vector<int>& arr, int threshold, int mid) {
    int sum = 0;
    int n = arr.size();  // Get the size of the array
    for (int i = 0; i < n; i++) {
        // Add the ceiling of arr[i] / mid to the sum
        sum += ceil((double)arr[i] / (double)mid);
    }
    // Return true if the sum is less than or equal to the threshold, else false
    return sum <= threshold;
}

// Function to find the smallest divisor such that the sum is <= threshold
int smallestDivisor(vector<int>& arr, int threshold) {
    int n = arr.size();
    int maxi = INT_MIN;  // Initialize to a very small value to find the maximum element in the array

    // Find the maximum value in the array
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    // Initialize low and high for binary search
    int low = 1, high = maxi;
    int ans = -1;

    // Binary search to find the smallest divisor
    while (low <= high) {
        int mid = (low + high) / 2;  // Find the middle point
        
        // If the sum for the current mid divisor is less than or equal to the threshold
        if (sum(arr, threshold, mid)) {
            ans = mid;  // Potential answer
            high = mid - 1;  // Try to find a smaller divisor
        } else {
            low = mid + 1;  // Increase the divisor to reduce the sum
        }
    }

    // Return the smallest divisor found
    return ans;
}

int main() {
    int n, threshold;
    // Input the number of elements and the threshold
    cin >> n >> threshold;
    
    // Input the array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and output the smallest divisor
    int divisor = smallestDivisor(arr, threshold);
    cout << divisor << endl;

    return 0;
}
