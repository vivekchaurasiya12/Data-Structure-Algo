#include<bits/stdc++.h>
using namespace std;
string convertDeciToBinary(int n){
    if (n == 0) return "0"; // Special case for n = 0
    string res ="";
    while(n>0){
    if(n%2==1) res +="1";
    else res +="0";
    n = n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string st = convertDeciToBinary(13);
    cout<<st;  
}