#include<bits/stdc++.h>
using namespace std;
void checkSorted(vector<int> &arr,int n){

    for(int i=0;i<n-1;i++){
        if(arr[i+1]>=arr[i]){

        }
        else{
            cout<<"Not sorted";
            break;
        }
    }
    cout<<"sorted";
}
int main(){

int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
checkSorted(arr,n);
return 0;
}