#include <bits/stdc++.h>
using namespace std;

vector<int> rotateElement(vector<int>& arr, int n) {
    if (n <= 1) return arr; // Handle edge case for empty or single-element array
    
    int temp = arr[0]; // Store the first element
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i]; // Shift elements to the left
    }
    arr[n - 1] = temp; // Place the first element at the end
    return arr; // Return the rotated array
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> newArray = rotateElement(arr, n); // Rotate and get the new array

    // Print the rotated array
    cout << "Rotated array: ";
    for (auto it : newArray) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
