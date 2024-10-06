#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number in the array
int maxNum(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

// Function to calculate the total hours required if Koko eats at rate 'mid'
int calculateTotalHour(vector<int> &arr, int n, int mid) {
    int totalHour = 0;
    for (int i = 0; i < n; i++) {
        totalHour += ceil((double)arr[i] / (double)mid);
    }
    return totalHour;
}

// Function to find the minimum eating rate using binary search
int kokoEatingBanana(vector<int> &arr, int n, int h) {
    int low = 1;
    int high = maxNum(arr, n);  // Maximum number in the array
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;
        int totalHour = calculateTotalHour(arr, n, mid);
        
        if (totalHour <= h) {
            // If Koko can finish within 'h' hours, store 'mid' as a potential answer
            ans = mid;
            high = mid - 1;  // Try to minimize further
        } else {
            low = mid + 1;  // Increase the rate to reduce total hours
        }
    }
    
    return ans;  // Minimum eating rate found
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minRate = kokoEatingBanana(arr, n, h);
    cout << minRate << endl;

    return 0;
}
