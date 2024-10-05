#include<bits/stdc++.h>
using namespace std;

// Function to find the single element in a sorted array
int singleElementInSortedArray(vector<int> &arr , int n){
    // Edge case: if the array has only one element, return it
    if(n == 1) return arr[0];
    
    // Check if the first or the last element is the unique one
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    
    // Initialize binary search range (ignoring the first and last elements since they are already checked)
    int low = 1, high = n - 2;
    
    // Perform binary search
    while(low <= high){
        int mid = (low + high) / 2; // Compute the middle index
        
        // If the middle element is unique (not equal to its neighbors), return it
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }
        
        // Decide which half to search based on the pattern
        // If `mid` is odd and arr[mid] matches the previous element, or if `mid` is even and arr[mid] matches the next element,
        // it means the single element is in the right half, so move `low` to `mid + 1`
        if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])){
            low = mid + 1;
        }
        else {
            // Otherwise, the single element is in the left half, so move `high` to `mid - 1`
            high = mid - 1;
        }
    }
    
    // In theory, this line is unreachable, but it's good to return a default value in case of unforeseen cases
    return -1;
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n); // Initialize the vector to store the array elements
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the function to find the single element
    int num = singleElementInSortedArray(arr, n);
    
    // Output the result
    cout << num << endl;
    
    return 0;
}
