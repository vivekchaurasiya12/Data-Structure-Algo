#include <bits/stdc++.h>
using namespace std;

bool isIthBitSet(int N, int i) {
     // Check if the bit at bitPosition in number is set
    if ((N & (1 << i)) != 0) {
        return true;
    }
    return false;
}

int main() {
    bool isBitSet = isIthBitSet(13, 1);  // Check if the 1st bit of 13 is set
    cout << isBitSet << endl;
}
