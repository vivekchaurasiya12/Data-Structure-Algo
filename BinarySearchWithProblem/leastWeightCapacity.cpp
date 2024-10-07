#include<bits/stdc++.h>
using namespace std;

// Function to calculate how many days are required to transport all items
// given a specific weight capacity (mid)
int daysRequired(vector<int> &arr, int mid) {
    int days = 1, load = 0;  // Initialize day count and current load
    int n = arr.size();
    
    // Traverse through all items
    for (int i = 0; i < n; i++) {
        // If adding the current item exceeds the current capacity (mid),
        // start a new day and reset the load
        if (load + arr[i] > mid) {
            days++;          // Increment day count
            load = arr[i];   // New load starts with the current item
        } else {
            load += arr[i];  // Accumulate the current item in the day's load
        }
    }
    
    return days;  // Return total number of days required
}

// Function to find the least weight capacity required to transport items
// in the given number of days using binary search
int leastWeightCapacity(vector<int> &arr, int days) {
    // The minimum capacity must be at least the heaviest item
    int low = *max_element(arr.begin(), arr.end());
    // The maximum capacity could be the sum of all items
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = high;  // Initialize answer with the highest possible value
    
    // Binary search for the minimum capacity
    while (low <= high) {
        int mid = (low + high) / 2;
        int noOfDays = daysRequired(arr, mid);  // Calculate days needed with this capacity
        
        // If it can be done within or less than the given number of days,
        // we try to minimize the capacity further
        if (noOfDays <= days) {
            ans = mid;       // Update the answer
            high = mid - 1;  // Try a smaller capacity
        } else {
            // If more days are required, increase the capacity
            low = mid + 1;
        }
    }
    
    return ans;  // Return the minimum capacity found
}

int main() {
    int n, days;
    cin >> n >> days;  // Read number of items and number of days
    vector<int> arr(n);
    
    // Read the weights of the items
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Find the least weight capacity required and output the result
    int weight = leastWeightCapacity(arr, days);
    cout << weight << endl;
    
    return 0;
}
