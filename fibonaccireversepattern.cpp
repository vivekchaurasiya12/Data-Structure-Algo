#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n =5;
    
   
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    while (fib.back() < 377) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int idx = fib.size() - 1;

    // Print right triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << fib[idx--] << " ";
        }
        cout << endl;
    }

    return 0;
}
