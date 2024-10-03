#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr, int n) {
    int index = -1;

    // Step 1: Find the first decreasing element from the end
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: If no such element is found, reverse the entire array
    if (index == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // Step 3: Find the next larger element to swap with arr[index]
    for (int i = n - 1; i > index; i--) {
        if (arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }

    // Step 4: Reverse the array from index + 1 to end to get the next permutation
    reverse(arr.begin() + index + 1, arr.end());

    return arr;  // Return the modified array
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

    // Find the next permutation
    vector<int> newArray = nextPermutation(arr, n);

    // Output the result
    for (auto it : newArray) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}
