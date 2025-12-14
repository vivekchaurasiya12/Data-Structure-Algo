#include<bits/stdc++.h>
using namespace std;
bool checkArraypresent(vector<int> &arr,vector<int> &temp){
    int j = 0;
    for (int i = 0; i < (int)arr.size() && j < (int)temp.size(); ++i) {
        if (arr[i] == temp[j]) {
            ++j;
        }
    }
    return j == (int)temp.size();
}
int main(){
int n; 
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int x;
cin>>x;
vector<int> temp(x);
for(int i=0;i<x;i++){
    cin>>temp[i];
}

bool check = checkArraypresent(arr,temp);
if(check){
    cout<<"true";
}else{
    cout<<"false";
}

return 0;
}