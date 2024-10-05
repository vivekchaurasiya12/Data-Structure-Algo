#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n) {
    if (n == 0) return 0;  // Handle edge case where n is 0
    int ans = 1;
    int low = 1, high = n;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow in mid calculation
        long long val = (long long)mid * mid;  // Ensure no overflow during multiplication

        if (val <= n) {
            ans = mid;  // Mid is a potential answer, move right to find larger roots
            low = mid + 1;
        } else {
            high = mid - 1;  // Move left to find smaller values
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    int num = squareRoot(n);
    
    cout << num;
    
    return 0;
}
