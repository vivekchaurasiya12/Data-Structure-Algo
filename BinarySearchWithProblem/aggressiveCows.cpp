#include<bits/stdc++.h>
using namespace std;

// Function to check if we can place the cows with at least 'dist' distance apart
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size();
    int cntcows = 1; // First cow placed at the first stall
    int last = stalls[0]; // Position of the last placed cow
    
    // Try placing the rest of the cows
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) { // Check if current stall is far enough from last placed cow
            cntcows++; // Place the cow
            last = stalls[i]; // Update the position of the last placed cow
        }
        if (cntcows >= cows) return true; // If all cows are placed, return true
    }
    return false; // If not all cows are placed, return false
}

// Function to find the largest minimum distance possible using binary search
int aggressiveCows(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end()); // Sort the stalls for ordered placement
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0]; // Binary search range for distances
    int ans = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2; // Check mid distance
        if (canWePlace(stalls, mid, cows) == true) {
            ans = mid; // If possible to place cows, update answer
            low = mid + 1; // Try for a larger distance
        }
        else {
            high = mid - 1; // If not possible, try for a smaller distance
        }
    }
    return ans; // Return the largest minimum distance found
}

int main() {
    int n, cows;
    cin >> n >> cows; // Input number of stalls and cows
    vector<int> stalls(n);
    
    for (int i = 0; i < n; i++) {
        cin >> stalls[i]; // Input stall positions
    }
    
    int num = aggressiveCows(stalls, cows); // Find the largest minimum distance
    cout << num << endl; // Output the result
    return 0;
}
