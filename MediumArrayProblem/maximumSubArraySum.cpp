#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum
int maximumSubArraySum(vector<int> &arr, int n) {
   int maxi = INT_MIN;  // To track the maximum sum
   int sum = 0;         // To keep track of the current subarray sum
  
   // Loop through the array
   for(int i = 0; i < n; i++) {
       sum = sum + arr[i];  // Add the current element to the sum
       
       // Update the maximum sum if the current sum exceeds it
       if(sum > maxi) {
           maxi = sum;
       }
       
       // If the current sum is negative, reset it to 0
       if(sum < 0) {
           sum = 0;
       }
   }
   
   // Return the maximum subarray sum or 0 if all sums are negative
   return maxi < 0 ? 0 : maxi;
}

int main() {
    int n;
    
    // Input the number of elements in the array
    cin >> n;
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and output the maximum subarray sum
    int maxi = maximumSubArraySum(arr, n);
    cout << maxi << endl;

    return 0;
}
