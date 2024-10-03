#include<bits/stdc++.h>
using namespace std;

// Function to find the upper bound of 'x' in the array
int upperBound(vector<int> &arr, int n, int x){
    int low = 0;        // Initialize the low pointer to the start of the array
    int high = n - 1;   // Initialize the high pointer to the end of the array
    int ub = n;         // Initialize ub to n (out of bounds) to store potential upper bound index
    
    // Binary search loop to find the upper bound
    while(low <= high){
        int mid = (high + low) / 2; // Calculate the mid-point of the current range
        
        // If the middle element is strictly greater than 'x'
        if(arr[mid] > x){
            ub = mid;        // Update the upper bound to mid (possible position to insert 'x')
            high = mid - 1;  // Move the high pointer to the left half
        }
        else{
            low = mid + 1;   // Move the low pointer to the right half if arr[mid] <= x
        }
    }
    return ub;  // Return the calculated upper bound index
}

int main(){
    int n, x;
    cin >> n >> x; // Input the size of the array and the target element 'x'
    
    vector<int> arr(n); // Declare a vector of size 'n'
    
    // Input array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int ub = upperBound(arr, n, x); // Call the upper bound function
    
    cout << ub << endl; // Output the upper bound index
    return 0;
}
