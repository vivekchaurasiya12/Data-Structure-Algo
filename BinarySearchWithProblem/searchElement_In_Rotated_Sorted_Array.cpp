#include <bits/stdc++.h> // Include standard libraries for input/output and utilities
using namespace std;

// Returns the index of the target element if found, else returns -1
int SearchElement(vector<int> &arr, int low, int high, int target) {
   int n = arr.size();

   while (low <= high) 
   { 
       int mid = (low + high) / 2; 
       if (arr[mid] == target) 
           return mid; 

       // Check if the left half is sorted
       if (arr[low] <= arr[mid]) {
           // Check if the target is within the sorted left half
           if (arr[low] <= target && target <= arr[mid]) {
               high = mid - 1; // Narrow down to the left half
           } else {
               low = mid + 1; // Target is in the right half
           }
       } else { // Right half must be sorted
           // Check if the target is within the sorted right half
           if (arr[mid] <= target && target <= arr[high]) {
               low = mid + 1; // Target is in the right half
           } else {
               high = mid - 1; // Narrow down to the left half
           }
       }
   }
   return -1;
}

int main() {
    int n, target;

    // Input the number of elements in the array and the target element
    cin >> n >> target;

    // Declare a vector of size n to store the array elements
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the binary search function with the entire array range [0, n-1]
    int num = SearchElement(arr, 0, n - 1, target);

    // Output the result, which is the index of the target or -1 if not found
    cout << num << endl;

    return 0; 
} 
