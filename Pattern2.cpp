#include<iostream>
using namespace std;
void print(int n){
    int num  = 1;
    int x = 2;
    for(int i=0;i<n;i++){  
           for(int j=0;j<=n-i-1;j++){
              cout<<"  ";
           }
           //star
        if(i==0){
           cout<<"  "<<num;
           num++;
        }else{
        for(int j=0;j<2*x+1;j++){
            if((i+j)%2==0){
                cout<<num<<" ";
                num++;
            }else{
              cout<<"* "; 
            }
          
        }
        x++;

        }

        
        //space
           for(int j=0;j<=n-i-1;j++){
              cout<<"  ";
           }
           cout<<endl;   
    }
}
 

int main(){
   
   
    int n;
    cin>>n;
   
    print(n);
   
  
   
  

}