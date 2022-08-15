#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;cin>>t;
    while(t--){
        long long int y,x,n;cin>>y>>x;
        if(y>x){
           if(y%2==0){
              n=y*y;
              n=n-x+1;
             
           }
           else{
              n=(y-1)*(y-1)+1;
              n=n+x-1;
             
           }
        }
        else{
            if(x%2==1){
               n=x*x;
               n=n-y+1;
               
            }
            else{
                n=(x-1)*(x-1)+1;
                n=n+y-1;
               
            }
            
        }
         
       cout<<n<<endl;
    }
    return 0;