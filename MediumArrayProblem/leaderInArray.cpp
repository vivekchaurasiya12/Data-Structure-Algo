#include <bits/stdc++.h>
using namespace std;

vector<int> leaderInArray(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    vector<int> temp;
    
    // Traverse the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] > maxi) {
            temp.push_back(arr[i]); // Add leader to the result
        }
        maxi = max(maxi, arr[i]); // Update maximum
    }
    
    //  Reverse the result to maintain the original order of leaders
    //sort is used to sort the array
    sort(temp.begin(), temp.end());
    
    return temp;  // Return the modified array
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

    // Find leaders in the array
    vector<int> newArray = leaderInArray(arr, n);

    // Output the result
    for (auto it : newArray) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
