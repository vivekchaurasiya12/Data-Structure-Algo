#include <bits/stdc++.h>  // Includes all standard libraries for convenience
using namespace std;

int MAX_CHAR = 256;  // Defines the number of distinct ASCII characters

// OPTIMIZED APPROACH WITH TIME COMPLEXITY O(N) AND SPACE COMPLEXITY O(1)
bool isIsomorphic(string s1, string s2) {
    if (s1.length() != s2.length()) return false;  // If lengths differ, they can't be isomorphic

    // Vectors to store the first occurrence index of each character in s1 and s2
    vector<int> m1(MAX_CHAR, -1);  // Initialize m1 with -1 for all 256 characters
    vector<int> m2(MAX_CHAR, -1);  // Initialize m2 with -1 for all 256 characters

    for (int i = 0; i < s1.length(); ++i) {
        // If the character's first occurrence hasn't been recorded, store the index
        if (m1[s1[i]] == -1) {
            m1[s1[i]] = i;  // Store the first occurrence index of s1[i]
        }
        if (m2[s2[i]] == -1) {
            m2[s2[i]] = i;  // Store the first occurrence index of s2[i]
        }

        // Check if the first occurrence indices match between s1 and s2
        // If they don't match, the strings are not isomorphic
        if (m1[s1[i]] != m2[s2[i]]) {
            return false;
        }
    }
    return true;  // If all indices match, the strings are isomorphic
}

/*
 * Another approach using unordered_map with T.C O(n) and S.C O(MAX_CHAR).
 * This approach stores character mappings in two unordered_maps (one for each string),
 * and checks if the first occurrence indices match.
 */
/*
bool isIsomorphic(string &s1, string &s2) {
    if (s1.length() != s2.length()) return false;  // Length check

    unordered_map<char, int> m1, m2;  // Maps to store first occurrence indices
    for (int i = 0; i < s1.length(); ++i) {
        // If character not seen before, store its first occurrence index
        if (m1.find(s1[i]) == m1.end()) {
            m1[s1[i]] = i;
        }
        if (m2.find(s2[i]) == m2.end()) {
            m2[s2[i]] = i;
        }

        // Check if the first occurrence indices match
        if (m1[s1[i]] != m2[s2[i]]) {
            return false;
        }
    }
    return true;
}
*/

int main() {
    string s = "aab";  // First input string
    string t = "xxy";  // Second input string

    // Check if the strings are isomorphic
    if (isIsomorphic(s, t)) {
        cout << "string is Isomorphic";  // Output if strings are isomorphic
    } else {
        cout << "string is not isomorphic";  // Output if strings are not isomorphic
    }
    return 0;  // End of program
}
