#include<bits/stdc++.h>
using namespace std;
int convertBinaryToDecimal(string &st){
    int len  = st.length();
    int pow2 = 1;
    int num = 0;
    for(int i=len-1;i>=0;i--){
         if(st[i]=='1'){
            num = num + pow2;
         }
         pow2 = pow2*2;
    }
    return num;
}
int main(){

    string st = "1101";
    int num = convertBinaryToDecimal(st);
    cout<<num;
}
