#include <bits/stdc++.h>
using namespace std;

// Function to sort the string using Bubble Sort
string sortString(string str) {
    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = 0; j < str.size() - i - 1; j++) {
            // Compare characters and swap if needed
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);  // Simple swap
            }
        }
    }
    return str;
}

int main() {
    string str = "surrounding";
    cout << "Original string: " << str << endl;

    // Sorting the string
    string newString = sortString(str);
    cout << "Sorted string: " << newString << endl;

    return 0;
}
