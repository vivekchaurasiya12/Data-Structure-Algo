#include<bits/stdc++.h> 
using namespace std;

// Function to find the minimum element in a rotated sorted array
int totalRotation(vector<int> &arr, int n) {
    int low = 0;          
    int high = n - 1;   
    int ans = INT_MAX;     
    int index = -1;    
    while (low <= high) {
        int mid = (low + high) / 2;   // Calculate the middle index
        
        // If the subarray [low...high] is already sorted, the minimum element is at 'low'
        if (arr[low] <= arr[high]) {
             return low;  // If the array is sorted, the minimum element is at the 'low' index, which also indicates the number of rotations
        }

        // If the left half [low...mid] is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans =  arr[low];  // Update the minimum element
                index = low;      // Track the index of the minimum element
            }
            low = mid + 1;        
        } 
       
        // If the right half [mid...high] is sorted
        else {
             if (arr[mid] < ans) {
                ans =  arr[mid];  // Update the minimum element
                index = mid;      // Track the index of the minimum element
            }
            high = mid - 1;       // Narrow the search to the left half
        }
    }
    
    return index;   // Return the index of the minimum element, which represents the total rotations
}

int main() {
    int n;
    cin >> n;  // Input the size of the array
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to find the minimum element and total rotations
    int index = totalRotation(arr, n);

    // Output the index of the minimum element (total rotations)
    cout << index << endl;

    return 0;
}
