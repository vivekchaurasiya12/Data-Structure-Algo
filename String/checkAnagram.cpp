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
// Optimal approach for chekcing anagram 

// bool checkAnagram(string str1,string str2){
//      int freq[26] = {0};
//      for(int i=0;i<str1.length();i++){
//         freq[str1[i]-'a']++;
//      }
//      for(int i=0;i<str2.length();i++){
//         freq[str2[i]-'a']--;
//      }
//     for(int i=0;i<26;i++){
//         if(freq[i]!=0) return false;
//     }
//      return true;
// }

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
