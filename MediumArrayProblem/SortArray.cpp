#include <bits/stdc++.h>
using namespace std;

// Function to sort the array with 0s, 1s, and 2s using Dutch National Flag Algorithm
vector<int> sortArray(vector<int> &arr, int n) {
    int low = 0;    // Pointer to place the next 0
    int mid = 0;    // Pointer to traverse the array
    int high = n - 1; // Pointer to place the next 2

    // Traverse the array until mid passes high
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]); // Move 0 to the start
            mid++;
            low++;
        }
        else if (arr[mid] == 1) {
            mid++; // Keep 1 in the middle
        }
        else {
            swap(arr[mid], arr[high]); // Move 2 to the end
            high--;
        }
    }

    return arr; // Return the sorted array
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
    
    // Sort the array using the sortArray function
    vector<int> newArray = sortArray(arr, n);
    
    // Output the sorted array
    for (auto it : newArray) {
        cout << it << " ";
    }

    return 0;
}
