#include<bits/stdc++.h>
using namespace std;
vector<int> moveZeroFirst(vector<int> &arr,int n){
    
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
     int size = n - temp.size();
    for(int i=0;i<size;i++){
        arr[i]=0;
    }
    int j=0;
    for(int i=size;i<n;i++){
        arr[i]=temp[j];
        j++;
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

vector<int> newArray = moveZeroFirst(arr,n);

for(int i=0;i<n;i++){
    cout<<newArray[i]<<" ";
}
return 0;
}