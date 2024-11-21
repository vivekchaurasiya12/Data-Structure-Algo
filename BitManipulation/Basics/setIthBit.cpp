#include <bits/stdc++.h>
using namespace std;

// Function to set the ith bit in the given number N
int setIthBit(int N, int i) {
    // Create a mask with only the ith bit set (1 << i)
    // Perform a bitwise OR with N to set the ith bit
    int newNum = (N | (1 << i));
    return newNum;
}

int main() {
    // Call setIthBit function to set the 1st bit in the number 13
    int num = setIthBit(13, 1);
    
    // Print the result after setting the 1st bit
    cout << num << endl;  // Output should be 15, since setting the 1st bit of 13 (binary 1101) makes it 15 (binary 1111)
}
