#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr, int n) {
    // If array has only one element, return index 0
    if(n == 1) return 0;
    
    // Check if the first element is a peak
    if(arr[0] > arr[1]) return 0;
    
    // Check if the last element is a peak
    if(arr[n-1] > arr[n-2]) return n-1;
    
    // Binary search between 1 and n-2, as edges are already checked
    int low = 1, high = n-2;
    while(low <= high) {
        int mid = (low + high) / 2;
        
        // Check if the middle element is a peak
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return mid;
        }
        // If arr[mid] is greater than arr[mid-1], move to the right half
        else if(arr[mid] > arr[mid-1]) {
            low = mid + 1;
        }
        // Otherwise, move to the left half
        else {
            high = mid - 1;
        }
    }
    
    // If no peak is found, return -1 (should not happen in a valid input)
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Find peak element's index
    int index = peakElement(arr, n);
    
    // Output the index of the peak element
    cout << index;
    
    return 0;
}
