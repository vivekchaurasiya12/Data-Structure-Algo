#include <bits/stdc++.h> // Include standard libraries for input/output and utilities
using namespace std;

// This function performs a binary search to find the target element in a rotated sorted array.
// If the target is found, it returns true, otherwise it returns false.
bool SearchElement(vector<int> &arr, int low, int high, int target) {
   int n = arr.size();

   
   while (low <= high) 
   { 
      
       int mid = (low + high) / 2; 
       
       // If the target element is found at the middle, return true
       if (arr[mid] == target) 
           return true; 

       // Handle cases where low, mid, and high elements are equal
       // Increment low and decrement high to skip duplicates and continue search
       if(arr[low] == arr[mid] && arr[mid] == arr[high]){
           low++;
           high--;
           continue;
       }

       // Check if the left half of the array is sorted
       if (arr[low] <= arr[mid]) {
           // If the target is in the sorted left half, narrow the search range to the left half
           if (arr[low] <= target && target <= arr[mid]) {
               high = mid - 1; // Target is in the left half
           } else {
               low = mid + 1; // Target is in the right half
           }
       } 
       // Otherwise, the right half must be sorted
       else {
           // If the target is in the sorted right half, narrow the search range to the right half
           if (arr[mid] <= target && target <= arr[high]) {
               low = mid + 1; // Target is in the right half
           } else {
               high = mid - 1; // Target is in the left half
           }
       }
   }

   return false;
}

int main() {
    int n, target;

    cin >> n >> target;

    vector<int> arr(n);

   for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the search function with the entire array range [0, n-1]
    bool num = SearchElement(arr, 0, n - 1, target);

    // Output the result: 1 if the target is found, or 0 if not found
    cout << num << endl;

    return 0; 
}
