#include<bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> &arr,int n,int d){
//Brute Approach

//  d=d%n;
//  int temp[d];
//  for(int i = 0;i<d;i++){
//     temp[i] = arr[i];
//  }
//  for(int i=d;i<n;i++){
//     arr[i-d]=arr[i];
//  }
//  int j=0;
//  for(int i=n-d;i<n;i++){
//     arr[i]=temp[j];
//     j++;
//  }

//Optimal Approach

    reverse(arr.begin(), arr.begin() + d);   // Reverse first 'd' elements
    reverse(arr.begin() + d, arr.end());     // Reverse the remaining elements
    reverse(arr.begin(), arr.end());         // Reverse the entire array
    return arr;
}
int main(){
int n,d;
cin>>n>>d;

vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<int> newArray = rotateArray(arr,n,d);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    
}

return 0;
}
