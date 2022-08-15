#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int 
 
int main(){
    ll n,m;cin>>n>>m;
 
    multiset<ll>price;
 
   
    for(int i=0;i<n;i++){
      ll x;cin>>x;
      price.insert(x);
    }
    for(int i=0;i<m;i++){
     ll x;cin>>x;
     auto it=price.upper_bound(x);
     if(it == price.begin()){
        cout<<-1<<endl;
     }
     else{
        cout<<*(--it)<<endl;
        price.erase(it);
     }
    }
 
    return 0;
}