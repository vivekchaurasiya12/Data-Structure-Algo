#include<bits/stdc++.h>
using namespace std;

// Linear Search function
int linearSearch(vector<int> &arr, int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;  // Return the index when the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int n, num;
    
    // Input the size of the array and the number to search for
    cin >> n >> num;
    
    vector<int> arr(n);
    
    // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Perform linear search
    int index = linearSearch(arr, n, num);
    
    // Output the result
    cout << index << endl;
    
    return 0;
}
