#include<bits/stdc++.h>
using namespace std;

// Returns the k-th missing number based on the given sorted array 'arr'
int KthMissingNumber(vector<int> &arr, int k) {
   int n = arr.size();
   int low = 0, high = n - 1;
   
   // Binary search approach to find the position where k-th missing number lies
   while(low <= high) {
       int mid = (low + high) / 2;
       
       // Calculate the number of missing numbers up to the current index 'mid'
       // This is derived by comparing the array value with what the value would be if there were no missing numbers
       int missing = arr[mid] - (mid + 1);
       
       // If the number of missing elements is less than k, we move to the right half
       if(missing < k) {
           low = mid + 1;
       }
       // Otherwise, move to the left half
       else {
           high = mid - 1;
       }
   }
   
   // The missing number will be at the position 'low', and we add 'k' to adjust for the number of missing values
   return low + k;
}

int main() {
    int n, k;

    // Input the number of elements in the array and the value of k (k-th missing number to find)
    cin >> n >> k;

    // Declare a vector of size n to store the array elements
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the KthMissingNumber function
    int num = KthMissingNumber(arr, k);

    // Output the result, which is the k-th missing number
    cout << num << endl;

    return 0; 
}
