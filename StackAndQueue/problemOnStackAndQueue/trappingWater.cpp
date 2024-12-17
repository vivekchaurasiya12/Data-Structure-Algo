#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& h) {
    // Initialize pointers, maximum heights, and the result
    int l = 0;                   // Left pointer
    int r = h.size() - 1;        // Right pointer
    int lmax = INT_MIN;          // Maximum height to the left of the current bar
    int rmax = INT_MIN;          // Maximum height to the right of the current bar
    int ans = 0;                 // Variable to store the total trapped water

    // Traverse the array using two pointers
    while (l < r) {
        lmax = max(lmax, h[l]); // Update the maximum height on the left
        rmax = max(rmax, h[r]); // Update the maximum height on the right

        // Calculate trapped water based on the smaller of the two maximum heights
        if (lmax < rmax) {
            ans += lmax - h[l]; // Water trapped at the current left bar
            l++;                // Move the left pointer inward
        } else {
            ans += rmax - h[r]; // Water trapped at the current right bar
            r--;                // Move the right pointer inward
        }
    }

    return ans; // Return the total trapped water
}
int main(){
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Call the trap function and display the result
    cout << "Total trapped rainwater: " << trap(heights) << " units" << endl;

    return 0;
}