#include <bits/stdc++.h>  // Includes all standard libraries of C++
using namespace std;

int main() {
    // 1. Creating a string "hello"
    string str = "hello";

    // 2. reverse the string "hello"
    // reverse(str.begin(), str.end());  // Reverses the string in-place
    // cout << str << endl;  // Prints the reversed string

    // 3. Print a substring of the first 3 characters of the string
    // Uncomment to display first 3 characters of the string "hello"
    // cout << str.substr(0, 3) << endl;  // Outputs "hel"

    // 4. Concatenating two strings using `+=`
    string s1 = "vivek";
    string s2 = "kumar";
    s1 += s2;  // Appends s2 to s1 (equivalent to s1 = s1 + s2)
    cout << s1 << " " << s2 << endl;  // Outputs: "vivekkumar kumar"

    // 5. Concatenating two C-style strings using `strcat()`
    char ch1[20] = "abcde";  // C-style string with enough space for concatenation
    char ch2[20] = "fghi";   // Another C-style string
    strcat(ch1, ch2);  // Concatenates ch2 to the end of ch1

    cout << ch1 << endl;  // Outputs: "abcdefghi"
    cout << strlen(ch1) << endl;  // Outputs the length of the concatenated string (9)

    return 0;  // Return 0 indicates successful execution of the program
}
