#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
    ll n,m;
    vector<ll>topo;
    vector<bool>vis(400000,0);
    vector<ll>out[400000];
    vector<ll>in[400000];
    vector<ll>cg(400000,-1);
  void dfs(ll i){
       vis[i]=1;
       for(auto c:out[i]){
        if(!vis[c])dfs(c);
       }
       topo.push_back(i);
    }
    void dfs2(ll i,ll u){
        cg[i]=u;
        for(auto c:in[i]){
            if(cg[c]==-1){
                dfs2(c,u);
            }
        }
    }
int main(){
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
      ll u,v;cin>>u>>v;
      out[u].push_back(v);
      in[v].push_back(u);
    }
 
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
    }
    reverse(topo.begin(),topo.end());
    //for(auto c:topo)cout<<c<<" ";
  //  vector<ll>kingdoms(n+1,-1);
    ll i=0;
    for(auto c:topo){
     if(cg[c]==-1){
        i++;
        dfs2(c,i);
     }   
    }
    cout<<i<<endl;
    for(int i=1;i<=n;i++){
        cout<<cg[i]<<" ";
    }
    cout<<"\n";
    return 0;
}