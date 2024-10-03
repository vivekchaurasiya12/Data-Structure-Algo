#include<bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of 'k' in the sorted array
int firstOccurance(vector<int> &arr, int n, int k){
   int low = 0, high = n-1;
   int first = -1; // Initialize 'first' to -1 to indicate that 'k' is not yet found
   
   // Binary search loop to find the first occurrence
   while(low <= high){
       int mid = (low + high) / 2; // Calculate the mid-point of the current range
       
       if(arr[mid] == k){
           first = mid;       // Update 'first' to the mid-point if 'k' is found
           high = mid - 1;    // Move the high pointer to continue searching in the left half
       }
       else if(arr[mid] < k){
           low = mid + 1;     // Move the low pointer to the right half if arr[mid] < k
       }
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
       
       if(arr[mid] == k){
           last = mid;        // Update 'last' to the mid-point if 'k' is found
           low = mid + 1;     // Move the low pointer to continue searching in the right half
       }
       else if(arr[mid] < k){
           low = mid + 1;     // Move the low pointer to the right half if arr[mid] < k
       }
       else{
           high = mid - 1;    // Move the high pointer to the left half if arr[mid] > k
       }
   }
   return last;  // Return the index of the last occurrence or -1 if not found
}

// Function to return the first and last occurrence of 'k'
pair<int, int> firstAndLastOccurance(vector<int> &arr, int n, int k){
    int first = firstOccurance(arr, n, k); // Find the first occurrence
    
    // If 'k' is not found, return {-1, -1}
    if(first == -1) return {-1, -1};
    
    int last = lastOccurance(arr, n, k); // Find the last occurrence
    
    return {first, last};  // Return a pair of the first and last occurrence indices
}

int main(){
    int n, k;
    cin >> n >> k;  // Input the size of the array and the target element 'k'
    
    vector<int> arr(n); // Declare a vector of size 'n'
    
    // Input array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Call the function to find first and last occurrence of 'k'
    pair<int, int> num = firstAndLastOccurance(arr, n, k);
    
    // Output the first and last occurrence indices
    cout << num.first << " " << num.second << endl;
    
    return 0;
}
