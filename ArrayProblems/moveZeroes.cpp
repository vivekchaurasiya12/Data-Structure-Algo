#include<bits/stdc++.h>
using namespace std;
vector<int> moveZero(vector<int> &arr,int n){
    
    // vector<int>temp;
    // for(int i=0;i<n;i++){
    //     if(arr[i]!=0){
    //         temp.push_back(arr[i]);
    //     }
    // }
    //  int size = temp.size();
    // for(int i=0;i<size;i++){
    //     arr[i]=temp[i];
    // }
    // for(int i=size;i<n;i++){
    //     arr[i]=0;
    // }

    //OPTIMAL APPROACH
  int j = -1; // Initialize j to -1, to find the first zero

    // Find the first zero in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i; // Store the index of the first zero
            break;
        }
    }

    // If no zero is found, the array doesn't need any changes
    if (j == -1) return arr;

    // From the first zero's position, start checking for non-zero elements
    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            // Swap non-zero element at index i with zero at index j
            swap(arr[i], arr[j]);
            j++; // Increment j to point to the next zero
        }
    }

    return arr; // Return the modified array
   
}
int main(){
int n; 
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}

vector<int> newArray = moveZero(arr,n);

for(int i=0;i<n;i++){
    cout<<newArray[i]<<" ";
}
return 0;
}