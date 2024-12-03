#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    // If the lengths of the strings are different, they can't be anagrams
    if(s.size() != t.size()) {
        return false;
    }

    // Sort both strings
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // After sorting, if both strings are the same, they are anagrams
    return s == t;
}

int main() {
    string s = "listen";
    string t = "silent";

    if (isAnagram(s, t)) {
        cout << "The strings are anagrams!" << endl;
    } else {
        cout << "The strings are not anagrams!" << endl;
    }

    return 0;
}
