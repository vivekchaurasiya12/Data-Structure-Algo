#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr) {
    // Sort the array to get the lexicographically smallest and largest strings
    sort(arr.begin(), arr.end());
    string s1 = arr[0];  // First string (smallest)
    string s2 = arr[arr.size() - 1];  // Last string (largest)

    // Find the minimum length between s1 and s2
    int minLength = min(s1.size(), s2.size());

    // Compare characters of s1 and s2 to find the common prefix
    string ans = "";
    for (int i = 0; i < minLength; i++) {
        if (s1[i] == s2[i]) {
            ans += s1[i];
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    vector<string> arr = {"flower", "flask", "flight"};
    string str = longestCommonPrefix(arr);
    cout << "Longest Common Prefix: " << str << endl;
    return 0;
}
