#include<bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of 'k' in the sorted array
int firstOccurance(vector<int> &arr, int n, int k){
   int low = 0, high = n-1;
   int first = -1; // Initialize 'first' to -1 to indicate that 'k' is not yet found
   
   // Binary search loop to find the first occurrence
   while(low <= high){
       int mid = (low + high) / 2; // Calculate the mid-point of the current range
       
       // If the middle element matches 'k'
       if(arr[mid] == k){
           first = mid;       // Update 'first' to the mid-point if 'k' is found
           high = mid - 1;    // Move the high pointer to continue searching in the left half
       }
       // If the middle element is less than 'k', search the right half
       else if(arr[mid] < k){
           low = mid + 1;     // Move the low pointer to the right half if arr[mid] < k
       }
       // If the middle element is greater than 'k', search the left half
       else{
           high = mid - 1;    // Move the high pointer to the left half if arr[mid] > k
       }
   }
   return first;  // Return the index of the first occurrence or -1 if not found
}

// Function to find the last occurrence of 'k' in the sorted array
int lastOccurance(vector<int> &arr, int n, int k){
   int low = 0, high = n-1;
   int last = -1;  // Initialize 'last' to -1 to indicate that 'k' is not yet found
   
   // Binary search loop to find the last occurrence
   while(low <= high){
       int mid = (low + high) / 2;  // Calculate the mid-point of the current range
       
       // If the middle element matches 'k'
       if(arr[mid] == k){
           last = mid;        // Update 'last' to the mid-point if 'k' is found
           low = mid + 1;     // Move the low pointer to continue searching in the right half
       }
       // If the middle element is less than 'k', search the right half
       else if(arr[mid] < k){
           low = mid + 1;     // Move the low pointer to the right half if arr[mid] < k
       }
       // If the middle element is greater than 'k', search the left half
       else{
           high = mid - 1;    // Move the high pointer to the left half if arr[mid] > k
       }
   }
   return last;  // Return the index of the last occurrence or -1 if not found
}

// Function to find the total number of occurrences of 'k' in the sorted array
int totalOccurance(vector<int>& arr, int n, int k){
    // Calculate total occurrences by finding last occurrence - first occurrence + 1
    int total = lastOccurance(arr, n, k) - firstOccurance(arr, n, k) + 1;
    return total;  // Return the total number of occurrences
}

int main(){
    int n, k;
    cin >> n >> k;  // Input the size of the array and the target element 'k'
    
    vector<int> arr(n); // Declare a vector of size 'n'
    
    // Input array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Call the function to find the total occurrences of 'k'
    int num = totalOccurance(arr, n, k);
    
    // Output the total occurrences of 'k'
    cout << num;
    
    return 0;
}
