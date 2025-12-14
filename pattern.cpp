#include<bits/stdc++.h>
using namespace std;
void printPattern(int n){
    int num = 0;
    int count =1;
    int num1 = 10;
    int count1=5;
   for(int i=1;i<=n;i++){
     num = num+count;
     if(i==2){
    for(int j=1;j<=i+1;j++){
        cout<<num<<" ";
        count++;
         num = num+count;
     }
     num = 6;
     count = 4;
     }else if(i==1){
        cout<<num<<" ";
        count++;
     }
     else{
    for(int j=1;j<=i+1;j++){
        num1 = num1+count1;
        cout<<num1<<" ";
        count1++;
        
        
     }
     }
   
     cout<<endl;

   }

}
int main(){
int n; 
cin>>n;
  
printPattern(n);




return 0;
}