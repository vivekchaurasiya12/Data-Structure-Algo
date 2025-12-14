#include<bits/stdc++.h>
using namespace std;
vector<int> swapArrayElements(vector<int> &arr,int n){
    for(int i=0;i<n;i=i+2){
        if(i!=n-1){
        swap(arr[i],arr[i+1]);
        }
    }
    return arr;
}
int main(){
int n; 
cin>>n;

vector<int> arr(n);

for(int i=0;i<n;i++){
    cin>>arr[i];
}
sort(arr.begin(),arr.end());
vector<int> newArray = swapArrayElements(arr,n);

for(int i=0;i<newArray.size();i++){
    cout<<newArray[i]<<" ";
}




return 0;
}