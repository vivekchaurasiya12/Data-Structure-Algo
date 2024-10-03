#include<iostream>
using namespace std;
void print1(int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<"*";
    }
    cout<<endl;
   }
 }
void print2(int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        cout<<"*"<<" ";
    }
    cout<<endl;
   }
 }
void print3(int n){
     for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
        cout<<j;
    }
    cout<<endl;
   }
}
void print4(int n){
 for(int i= 1;i<=n;i++)
 {
    for(int j=1;j<=i;j++){
        cout<<i<<" ";
    }
    cout<<endl;
 }
}
void print5(int n){
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void print6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void print7(int n){
    //space
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
void print8(int n){
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
void print9(int n){
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
   
}
void print10(int n){
    for(int i=0;i<=n;i++){
        if(i<=(n/2)){
            for(int j=0;j<i+1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        else{
            for(int j=0;j<(n-i+1);j++){
                cout<<"*";
            }
            cout<<endl;
            
        }
    }
}
void print11(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if((i+j)%2==0){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        } 
        cout<<endl;
    }
}
void print12(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}
void print13(int n){
    int k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<k<<" ";
            k++;
        }
       
        cout<<endl;
    }
}
void print14(int n){
    for(int i=0;i<n;i++){
        char ch ='A';
        for(int j=0;j<=i;j++){
            
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
void print15(int n){
     for(int i=0;i<n;i++){
        char ch ='A';
        for(int j=0;j<n-i;j++){
            
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
void print16(int n){
     char ch ='A';
 for(int i=0;i<n;i++){
       
        for(int j=0;j<=i;j++){
            
            cout<<ch;
            
        }
        ch++;
        cout<<endl;
    }
}
int main(){
   int t;
   cin>>t;
   for(int i=0;i<t;i++){
    int n;
    cin>>n;
   // print1(n);
    //print2(n);
    //print3(n);
    //print4(n);
    //print5(n);
    // print6(n);
    // print7(n);
    // print8(n);
    // print9(n);
   // print10(n);
//    print11(n);
    // print12(n);
    // print13(n);
    // print14(n);
    //  print15(n);
     print16(n);
   }

}