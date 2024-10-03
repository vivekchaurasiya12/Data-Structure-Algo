#include <bits/stdc++.h>
using namespace std;

int uniqueElement(vector<int>& arr, int n) {
    if (n == 0) return 0; // Handle case of empty array
    
    int i = 0; // Pointer for the last unique element
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) { // Found a new unique element
            arr[i + 1] = arr[j]; // Place it in the next position
            i++; // Move the unique pointer
        }
    }
    return i + 1; // Return count of unique elements
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array to ensure unique elements are adjacent
    sort(arr.begin(), arr.end());

    int num = uniqueElement(arr, n);
    cout << "Number of unique elements: " << num << endl;

    // Print the unique elements
    cout << "Unique elements: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
