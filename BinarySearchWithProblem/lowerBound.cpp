#include<bits/stdc++.h>
using namespace std;

// Function to find the lower bound of 'x' in the array
int lowerBound(vector<int> &arr, int n, int x){
    int low = 0;       // Initialize the low pointer to the start of the array
    int high = n-1;    // Initialize the high pointer to the end of the array
    int lb = n;        // Initialize lb to n (out of bounds) to store potential lower bound index
    
    // Binary search loop to find the lower bound
    while(low <= high){
        int mid = (high + low) / 2; // Calculate the mid-point of the current range
        
        // If the middle element is greater than or equal to 'x'
        if(arr[mid] >= x){
            lb = mid;      // Update the lower bound to mid
            high = mid - 1; // Move the high pointer to the left half
        }
        else{
            low = mid + 1;  // Move the low pointer to the right half if arr[mid] < x
        }
    }
    return lb;  // Return the calculated lower bound index
}

int main(){
    int n, x;
    cin >> n >> x; // Input the size of the array and the target element 'x'
    
    vector<int> arr(n); // Declare a vector of size 'n'
    
    // Input array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int lb = lowerBound(arr, n, x); // Call the lower bound function
    
    cout << lb << endl; // Output the lower bound index
    return 0;
}
