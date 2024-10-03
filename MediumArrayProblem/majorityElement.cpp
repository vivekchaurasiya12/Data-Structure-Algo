#include<bits/stdc++.h>
using namespace std;

// Function to find the majority element
int majorityElement(vector<int> &arr, int n) {
    int count = 0;  // Counter for the candidate majority element
    int elem;       // Potential majority element

    // First loop: Find the candidate majority element
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            count = 1;
            elem = arr[i];  // Set new candidate
        }
        else if (arr[i] == elem) {
            count++;  // Increment count if current element matches candidate
        }
        else {
            count--;  // Decrement count if current element doesn't match
        }
    }

    // Second loop: Verify if the candidate is actually the majority element
    int cnt = 0;  // Counter to check occurrences of the candidate
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            cnt++;
        }
    }

    // If the candidate occurs more than n/2 times, return it
    if (cnt > n / 2) {
        return elem;
    }

    return -1;  // Return -1 if there is no majority element
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

    // Find and output the majority element
    int num = majorityElement(arr, n);
    cout << num << endl;

    return 0;
}
