#include<bits/stdc++.h>
using namespace std;


// Returns the index of the target element if found, else returns -1
int bs(vector<int> &arr, int low, int high, int target) {
    // Base case: if low exceeds high, the target is not present in the array
    if (low > high) {
        return -1;
    }

    // Calculate the middle index
    int mid = (low + high) / 2;

    // If the target is found at the mid index, return the index
    if (arr[mid] == target) {
        return mid;
    }
    // If the target is greater than the mid element, search in the right half
    else if (target > arr[mid]) {
        return bs(arr, mid + 1, high, target);
    }
    // If the target is smaller than the mid element, search in the left half
    return bs(arr, low, mid - 1, target);
}

int main() {
    int n, target;

    // Input the number of elements in the array and the target element
    cin >> n >> target;

    // Declare a vector of size n to store the array elements
    vector<int> arr(n);

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the binary search function with the entire array range [0, n-1]
    int num = bs(arr, 0, n - 1, target);

    // Output the result, which is the index of the target or -1 if not found
    cout << num << endl;

    return 0; 
}
