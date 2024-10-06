#include<bits/stdc++.h>
using namespace std;

// This function checks if it is possible to make 'm' bouquets in 'days' days.
// Each bouquet requires 'k' consecutive flowers that bloom within 'days'.
bool possible(vector<int> arr, int days, int k, int m){
    int count = 0;  // To count the number of consecutive blooming flowers.
    int noOfBouquet = 0;  // To count how many bouquets can be formed.
    int n = arr.size();  // Size of the array representing blooming days.

    // Iterate through the array to check blooming flowers within 'days'.
    for(int i = 0; i < n; i++){
        if(arr[i] <= days){
            count++;  // If the flower blooms within 'days', increment count.
        }
        else {
            // If count reaches 'k', a bouquet is formed.
            noOfBouquet += count / k;
            count = 0;  // Reset the count when a non-blooming flower is encountered.
        }
    }

    // Add remaining bouquets from the last segment of consecutive blooming flowers.
    noOfBouquet += count / k;
    
    // Check if we can form at least 'm' bouquets.
    return noOfBouquet >= m;
}

// This function returns the minimum number of days required to make 'm' bouquets.
// Each bouquet requires 'k' consecutive blooming flowers.
int roseGarden(vector<int> arr, int k, int m) {
    int n = arr.size();
    int mini = INT_MAX;  // Initialize with the maximum possible value for comparison.
    int maxi = INT_MIN;  // Initialize with the minimum possible value for comparison.
    
    // Find the minimum and maximum number of days in the array (flower bloom times).
    for(int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    
    // Initialize binary search bounds.
    int low = mini;  // The minimum possible number of days.
    int high = maxi;  // The maximum possible number of days.
    int ans = high;  // Store the answer, initialized to the maximum days.
    
    // Edge case: If the total number of flowers is less than required flowers for 'm' bouquets.
    if(n < m * k) return -1;
    
    // Perform binary search to find the minimum number of days.
    while(low <= high){
        int mid = (low + high) / 2;
        
        // Check if it's possible to form 'm' bouquets in 'mid' days.
        if(possible(arr, mid, k, m)){
            ans = mid;  // Update the answer if possible.
            high = mid - 1;  // Try to find a smaller number of days.
        }
        else {
            low = mid + 1;  // Increase the number of days if it's not possible.
        }
    }
    return ans;  // Return the minimum number of days.
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;  // Input: number of flowers, number of bouquets, flowers per bouquet.
    
    vector<int> arr(n);  
    for(int i = 0; i < n; i++) {
        cin >> arr[i];  
    }
    
    int days = roseGarden(arr, k, m);  
    cout << days; 
    return 0;
}
