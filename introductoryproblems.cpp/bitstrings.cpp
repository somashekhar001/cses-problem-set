#include<iostream>
using namespace std;
 
int main(){
    int n;cin>>n;
 
    long long int mod=1e9+7;
     long long  int ans=1; 
     while(n--){
        ans=ans<<1;
        ans%=mod;
     }
     cout<<ans%mod<<endl;
    return 0;
}