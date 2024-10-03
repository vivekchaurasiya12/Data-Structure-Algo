#include<bits/stdc++.h>
using namespace std;
vector<int> rightRotate(vector<int> &arr,int n,int d){
    
//brute approach

    // d =d%n;
    // int temp[d];
    // int j=0;
    // for(int i=n-d;i<n;i++){
    //   temp[j] = arr[i];
    //   j++;
    // }
    // for(int i=n-d-1;i>=0;i--){
    //     arr[i+d] = arr[i];
    // }
    // for(int i=0;i<d;i++){
    //     arr[i]=temp[i];
    // }

//Optimal Approach

reverse(arr.begin(),arr.begin()+d+1);
reverse(arr.begin()+d+1,arr.end());
reverse(arr.begin(),arr.end());
return arr;
}
int main(){
int n,d;
cin>>n>>d;
vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<int> newArray = rightRotate(arr,n,d);
for(int i=0;i<n;i++){
    cout<<newArray[i]<<" ";
}

return 0;
}