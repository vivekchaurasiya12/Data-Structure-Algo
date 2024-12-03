#include<bits/stdc++.h>
using namespace std;
bool checkAnagram(string str1,string str2){
     int freq[26] = {0};
     for(int i=0;i<str1.length();i++){
        freq[str1[i]-'a']++;
     }
     for(int i=0;i<str2.length();i++){
        freq[str2[i]-'a']--;
     }
    for(int i=0;i<26;i++){
        if(freq[i]!=0) return false;
    }
     return true;
}
int main(){
    string str1 = "integer";
    string str2 = "tegerin";
    if(checkAnagram(str1,str2)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
 
    return 0;
}