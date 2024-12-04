#include<bits/stdc++.h>
using namespace std;

// approach 1:  with time complexity O(n²) using rotations

// This function rotates the string s and checks if it becomes equal to t.
// bool rotateString(string s, string t) { 
     // Rotate the string one character at a time
//     for(int i = 0; i < s.size(); i++) { 
//         rotate(s.begin(), s.begin() + 1, s.end());  // Rotate the string by 1 character
//         if(s == t)  // Check if the rotated string matches t
//             return true;  // Return true if a match is found
//     } 

     // If no rotation matches t, return false
//     return false; 
// } 


//  approach 2: optimized  to check if string 't' is a rotation of string 's'
// Time Complexity: O(n), where n is the length of the string
bool rotateString(string s, string t) {
    // Concatenate s with itself to handle all possible rotations of s
    string temp = s + s;
    
    // Check if 't' is a substring of 'temp'. If it is, then 't' is a rotation of 's'
    return temp.find(t) != string::npos; // Returns true if 't' is found in 'temp'
}

int main() {
    string s1 = "abcde"; // Original string
    string s2 = "bcdea"; // Rotated string
    
    // If s2 is a rotation of s1, print "true", otherwise print "false"
    if(rotateString(s1, s2)) {
        cout << "true";  // If true, s2 is a rotation of s1
    } else {
        cout << "false"; // If false, s2 is not a rotation of s1
    }
    
    return 0;
}
