#include<bits/stdc++.h>
using namespace std;

int minBitsFlip(int start, int goal) {
    int result = start ^ goal;  // XOR to find differing bits
    int count = 0;
    while (result != 0) {
        result = result & (result - 1);  // Remove the lowest set bit
        count++;
    }
    return count;
}

int main() {
    int num = minBitsFlip(10, 7);
    cout << num << endl;  // Output: 3
    return 0;
}
