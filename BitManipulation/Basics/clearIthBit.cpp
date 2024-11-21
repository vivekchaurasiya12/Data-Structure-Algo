#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Create a mask with the 2nd bit cleared (all bits are 1 except the 2nd bit, which is 0)
    int newNum = (N & (~(1 << 2)));

    // Output the result after clearing the 2nd bit
    cout << newNum;
}
