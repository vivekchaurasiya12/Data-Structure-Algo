#include <bits/stdc++.h>
using namespace std;


vector<int> reArrange(vector<int> &arr, int n) {
   vector<int> pos,neg;
   for(int i=0;i<n;i++){
    if(arr[i]>=0){
       pos.push_back(arr[i]);
    }
    else{
        neg.push_back(arr[i]);
    }
   }
   for(int i=0;i<n/2;i++){
    arr[2*i]=pos[i];
    arr[2*i+1]= neg[i];
   }

    return arr; // Return the sorted array
}

int main() {
    int n;
    
    // Input the number of elements in the array
    cin >> n;
    vector<int> arr(n);
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> newArray = reArrange(arr,n);
    for(auto it:newArray){
        cout<<it<<" ";
    }
    
   
    return 0;
}
