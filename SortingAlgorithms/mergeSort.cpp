#include<bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves of the array
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary array to store merged elements
    int left = low;   // Left half starting index
    int right = mid + 1; // Right half starting index

    // Merge the two halves into temp array in sorted order
    while ((left <= mid) && (right <= high)) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If any elements are left in the left half, add them to temp
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If any elements are left in the right half, add them to temp
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive function to divide the array into halves and sort
void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return; // Base case: if the array has 1 or no elements, return
    }
    
    int mid = (low + high) / 2; // Find the middle index to divide the array
    
    mergeSort(arr, low, mid); // Recursively sort the left half
    mergeSort(arr, mid + 1, high); // Recursively sort the right half
    
    merge(arr, low, mid, high); // Merge the sorted halves
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }

    mergeSort(arr, 0, n - 1); // Call mergeSort on the entire array

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the sorted array
    }

    return 0;
}
