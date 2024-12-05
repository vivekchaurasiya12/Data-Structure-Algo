#include <bits/stdc++.h>
using namespace std;

// Function to find the XOR of all numbers from 0 to n
int fun(int n) {
    // XOR of numbers from 0 to n follows a pattern based on n % 4:
    // n % 4 == 0 -> XOR from 0 to n is n
    // n % 4 == 1 -> XOR from 0 to n is 1
    // n % 4 == 2 -> XOR from 0 to n is n + 1
    // n % 4 == 3 -> XOR from 0 to n is 0
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    if (n % 4 == 3) return 0;
    if (n % 4 == 0) return n;
}

// Function to find the XOR of all numbers from l to r
int findXOR(int l, int r) {
    // XOR from l to r can be calculated as:
    // XOR(l to r) = XOR(0 to r) ^ XOR(0 to l-1)
    return fun(l - 1) ^ fun(r);
}

int main() {
    // Find and print the XOR of all numbers from 8 to 17
    cout << findXOR(8, 17);  // Output: 1
    return 0;
}
