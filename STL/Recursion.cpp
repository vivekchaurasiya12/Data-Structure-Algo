#include<bits/stdc++.h>
using namespace std;
bool palindrome(string str,int i){
    if(i>=str.length()/2){
        return true;
        }
        if(str[i]!=str[str.length()-i-1]){
            return false;
        }
       return palindrome(str,i+1);
}

int main()
{
 string str ;
 cin>>str;
 cout<<palindrome(str,0);
    
    return 0;
}