#include<bits/stdc++.h>
using namespace std;

int findNumThatAppearsOnce(vector<int>& arr,int n) {
   map<long long,int>mpp;
   for(int i=0;i<n;i++){
    mpp[arr[i]]++;
   }
   for(auto it:mpp){
    if(it.second ==1){
        return it.first;
    }
   }
   return -1;
}

int main() {
    int n;
    cin >> n;  // Input size of the array
    vector<int> arr(n); // Declare array of size n

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and print the number that appears once
    int num = findNumThatAppearsOnce(arr,n);
    cout << num << endl;

    return 0;
}
