#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int left = 0;
    int right = s.size() - 1;

    // Trim leading and trailing spaces
    while (left <= right && s[left] == ' ') left++;
    while (right >= left && s[right] == ' ') right--;

    string ans = "";
    string temp = "";

    // Traverse the string and build words
    while (left <= right) {
        char ch = s[left];
        if (ch != ' ') {
            temp += ch;  // Build the current word
        } else if (ch == ' ' && !temp.empty()) {
            // Add the word to the front of the result if it's not empty
            if (!ans.empty()) {
                ans = temp + " " + ans;
            } else {
                ans = temp;
            }
            temp = "";  // Reset temp for the next word
        }
        left++;
    }

    // Add the last word if any
    if (!temp.empty()) {
        if (!ans.empty()) {
            ans = temp + " " + ans;
        } else {
            ans = temp;
        }
    }

    return ans;
}

int main() {
    string st = "   TUF  is   great for   interview preparation  ";
    cout << "Before reversing words:" << endl;
    cout << st << endl;
    cout << "After reversing words:" << endl;
    cout << reverseWords(st) << endl;
    return 0;
}
