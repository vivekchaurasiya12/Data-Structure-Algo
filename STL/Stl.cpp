#include<bits/stdc++.h>
using namespace std;

int main(){
    //pair
//     pair<int,int>p = {8,5};
//     cout<<p.first<<" " <<p.second <<endl;

//    //Nested Pair
//     pair<int,pair<int,int>>x = {9,{4,5}};
//     cout<<x.first<<endl;
//     cout<<x.second.first<<endl;
//     cout<<x.second.second<<endl;

//     //array of pair
//     pair<int,int>arr[] = {{2,4},{4,8},{6,2}};
//     cout<<arr[2].first<<endl;

    // vector<int>v(3,9);
    // v.push_back(2);
    // v.emplace_back(9);
    // vector<int>:: iterator it = v.end();
    // it--;
    // cout<<*it<<endl;

    // vector<pair<int,int>>vec;
    // vec.push_back({3,1});
    // vec.emplace_back(4,3);
    // cout<<vec[1].first;

    // list<int> ls;
    // ls.push_back(3);
    // ls.push_front(8);
    //  ls.push_front(9);
    //   ls.push_front(2);
    //   for(auto it:ls){
    //     cout<<it<<" ";
    //   }

    // set<int> st;
    // st.insert(2);
    // st.insert(1);
    // st.insert(5);
    // auto it = st.find(3);
    // cout<<*it;

    // map<int,int> mpp;
    // mpp[1]=2;
    // mpp.insert({2,4});
    // mpp.emplace(3,2);
    // cout<<mpp[5]<<endl;


    // auto it = mpp.find(6);
    // cout<<it->first;
//    int arr[5]= {2,4,57,2,6};
//    int maxi = *min_element(arr , arr+5);
// cout<<maxi<<endl;

// int N;
// cin>>N;
// vector<int> v;
// for(int i=1;i<=sqrt(N);i++){
//     if(N%i==0){
//         v.push_back(i); 
//         if(N/i != i){
//             v.push_back(N/i);
//         }
//     }
// }
// sort(v.begin(),v.end());
// for(auto it:v){
//     cout<<it<<" ";
// }


// int N;
// cin>>N;
// int count = 0;
// for(int i=1;i<=sqrt(N);i++){
//     if(N%i==0){
//         count++;
//         if(N/i != i){
//             count++;
//         }
//     }
// }
// if(count==2){
// cout<<"number is prime";
// }
// else{
//     cout<<"not prime";
// }
int a,b;
cin>>a>>b;
while(a>0 && b>0){
    if(a>b){
        a=a%b;
    }
    else{
        b=b%a;
    }
}
if(a==0){
    cout<<b<<" "<<a;
}
else{
    cout<<a<<" "<<b;
    
}



    return 0;
}