#include <bits/stdc++.h>
using namespace std;

string largestOddNumberInString(string &str) {
    if (str.empty()) return "";  // Handle empty string case

    int index = -1;

    // Traverse the string from right to left to find the rightmost odd digit
    for (int i = str.size() - 1; i >= 0; i--) {
        if ((str[i] - '0') % 2 != 0) {  // Convert character to integer and check for odd
            index = i;
            break;
        }
    }

    // If no odd digit was found, return an empty string
    if (index == -1) return "";

    // Return the substring from the start to the index of the last odd digit
    return str.substr(0, index + 1);
}

int main() {
    vector<string> testCases = {"247", "42068", "1234567890", "", "2468", "13579"};
    
    for ( auto &test : testCases) {
        cout << "Input: " << test << "\nOutput: " << largestOddNumberInString(test) << "\n\n";
    }

    return 0;
}
