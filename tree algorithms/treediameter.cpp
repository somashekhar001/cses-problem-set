#include<bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
vector<ll>adj[200000];
void dfs(ll a,ll e,vector<ll>&depth){
    
  
     for(auto c:adj[a]){
           if(c!=e){
            depth[c]=depth[a]+1;
            dfs(c,a,depth);
           }
        
     }
    
}
   
 
 
int main(){
 ll n;cin>>n;
 
 for(int i=0;i<n-1;i++){
    ll a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
 }
 
      vector<ll>depth(n+1,0);
    dfs(1,0,depth);
    ll d=0,f=0;
    for(int i=1;i<=n;i++)
    {
      if(d<depth[i]){
        d=depth[i];
        f=i;
      }
    }
    depth.assign(n+1,0);
    dfs(f,0,depth);
    ll m=0;
    for(auto c:depth)m=max(m,c);
 
    cout<<m<<endl;
   return 0;
}