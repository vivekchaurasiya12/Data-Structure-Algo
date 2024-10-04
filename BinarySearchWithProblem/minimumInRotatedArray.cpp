#include<bits/stdc++.h> // Includes standard libraries
using namespace std;

// Function to find the minimum element in a rotated sorted array
int minimumInRotatedArray(vector<int> &arr, int n) {
    int low = 0;           // Starting index
    int high = n - 1;      // Ending index
    int ans = INT_MAX;     // Initialize answer with the maximum possible integer value
    
    while (low <= high) {
        int mid = (low + high) / 2;   // Calculate the middle index
        
        // If the subarray [low...high] is already sorted, the minimum is at 'low'
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]); // Update the minimum element
            break;                    // Exit the loop since the minimum is found
        }

        // If the left half [low...mid] is sorted, the minimum element lies in the left half
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]); // Update the minimum element with the first element in the sorted left half
            low = mid + 1;            // Narrow the search to the right half
        } 
        // If the right half [mid...high] is sorted, the minimum element lies in the right half
        else {
            ans = min(ans, arr[mid]);  // Update the minimum element with the middle element
            high = mid - 1;            // Narrow the search to the left half
        }
    }
    
    return ans;   // Return the minimum element found
}

int main() {
    int n;
    cin >> n;  // Input the size of the array
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to find the minimum element
    int num = minimumInRotatedArray(arr, n);

    // Output the minimum element
    cout << num << endl;

    return 0;
}
