#include<bits/stdc++.h>
using namespace std;

// Function to calculate mid^n and compare it with m
int power(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= mid;
        if (ans > m) return 2;  // Return 2 if the result exceeds m
    }
    if (ans == m) return 1;      // Return 1 if mid^n == m
    return 0;                    // Return 0 if mid^n < m
}

// Function to find the Nth root of M using binary search
int NthRoot(int n, int m) {
    int low = 1, high = m;
    
    // Binary search to find the Nth root
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = power(mid, n, m);
        
        if (midN == 1) {  // If mid^n == m
            return mid;
        } else if (midN == 0) {  // If mid^n < m, increase low
            low = mid + 1;
        } else {  // If mid^n > m, decrease high
            high = mid - 1;
        }
    }
    return -1;  // Return -1 if no integer root exists
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int result = NthRoot(n, m);
    
    if (result == -1)
        cout << "No integer root found.\n";
    else
        cout << "The " << n << "th root of " << m << " is: " << result << endl;
    
    return 0;
}
