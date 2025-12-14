#include<bits/stdc++.h>
using namespace std;
vector<int> convertToArray(int n){
    vector<int> temp;
    
    while(n>0){
        int lastDigit = n%10;
        temp.push_back(lastDigit);
        n=n/10;
     
    }
    return  temp;
}
vector<int> checkUnique(vector<int> &arr){
    vector<int> temp;

   for(int i=0;i<arr.size()-1;i++){
    if(arr[i]==arr[i+1]){
        temp.push_back(arr[i]);
    }
   }
   if(temp.size()>0){
    return temp;
   }
   return {};


}
int main(){
int n; 
cin>>n;
vector<int> arr = convertToArray(n);
sort(arr.begin(),arr.end());
vector<int> newArr = checkUnique(arr);

if(newArr.size()==0){
    cout<<"All digits are uniques";
}else{
    for(int i=0;i<newArr.size();i++){
       cout<<newArr[i]<<",";
    }
    cout<<"are not Unique";
    
}



return 0;
}