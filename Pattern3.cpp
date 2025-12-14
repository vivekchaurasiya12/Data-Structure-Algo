#include<bits/stdc++.h>
using namespace std;

void print(int n){
    
    if(1){
        for(int i=0;i<n;i++){
        //space
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        //star
        for( int j=0;j<2*(n-i)-1;j++){
            cout<<"* ";
        }
        //space
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        cout<<endl;
    }
    }
    if(1){
         for(int i=0;i<n;i++){  
           for(int j=0;j<n-i-1;j++){
              cout<<"  ";
           }
           //star
           for(int j=0;j<2*i+1;j++){
              cout<<"* ";  
        }    
        //space
           for(int j=0;j<n-i-1;j++){
              cout<<"  ";
           }
           cout<<endl;   
    }
    }
}

int main(){
    int n;
    cin>>n;
    print(n);
}
