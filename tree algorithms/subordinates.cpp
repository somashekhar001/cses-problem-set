#include<bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
vector<ll>adj[200000];
 
void dfs(ll a,ll e,vector<ll>&depth ){
    
    for(auto c:adj[a]){
        if(c!=e){
            dfs(c,a,depth);
            depth[a]=depth[a]+depth[c]+1;
        }
    }
 
}
//9 7 5 0 3 0 2 0 1 0 
int main(){
 ll n;cin>>n;
 
 for(int i=2;i<=n;i++){
    ll a;cin>>a;
    adj[a].push_back(i);
 }
 vector<ll>depth(n+1,0);
 
 dfs(1,0,depth);
// depth[1]=n-1;
 for(ll i=1;i<=n;i++) cout<<depth[i]<<" ";
 
 cout<<endl;     
   return 0;
}