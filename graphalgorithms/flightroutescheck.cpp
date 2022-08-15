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
    void dfs2(ll i){
        cg[i]=1;
        for(auto c:in[i]){
            if(cg[c]==-1){
                dfs2(c);
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
    dfs2(topo[0]);
   
    bool b;
    ll l=topo[0],r=-1;
    for(int i=1;i<=n;i++){
        if(cg[i]==-1){
            r=i;
           break;
        }
    }
    if(r==-1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
        cout<<r<<" "<<l<<endl;
    }
    
 
    return 0;
}