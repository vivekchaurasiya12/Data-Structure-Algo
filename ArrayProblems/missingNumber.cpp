#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int n) {
    int xor1 = 0;  // XOR for numbers 1 to n
    int xor2 = 0;  // XOR for array elements

    // XOR all elements of the array and numbers from 1 to n-1 in one loop
    for(int i = 0; i < n-1; i++) {
        xor2 ^= arr[i];  // XOR of array elements
        xor1 ^= (i + 1);  // XOR of numbers from 1 to n-1
    }

    // XOR the last number n
    xor1 ^= n;

    // The result will be the missing number
    return xor1 ^ xor2;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n-1);  // Input array of size n-1

    for(int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    int num = missingNumber(arr, n);
    cout << num << endl;

    return 0;
}
