#include <bits/stdc++.h>
using namespace std;

int numberOfSubArraywithXOR(vector<int> &arr, int k) {
    int n = arr.size();
    map<int, int> mpp;
    mpp[0] = 1; // For the case where subarray starts from index 0
    int xr = 0; // This will store the XOR of elements from 0 to i
    int count = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i]; // Update current XOR

        int x = xr ^ k; // Find if there exists a prefix with XOR equal to this

        count += mpp[x]; // Add the number of times we've seen this XOR

        mpp[xr]++; // Update the map with the current XOR
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int count = numberOfSubArraywithXOR(arr, k);
    cout << count << endl;

    return 0;
}
