#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
vector<ll>topo;
vector<bool>vis;
 
 
 
int main(){
  ll n,m;cin>>n>>m;
  vector<ll>cnt(n+1,0);
  vector<ll>adj[n+1];
 
  for(int i=0;i<m;i++){
    ll u,v;cin>>u>>v;
    adj[u].push_back(v);
    cnt[v]++;
  }
  vis.assign(n+1,0);
  
  for(int i=1;i<=n;i++){
    if(cnt[i]==0 && !vis[i]){
 
     queue<ll>q;
     q.push(i);
     vis[i]=1;
     while(!q.empty()){
        ll v=q.front();
        q.pop();
        vis[v]=1;
        topo.push_back(v);
        for(auto c:adj[v]){
            cnt[c]--;
            if(cnt[c]==0)q.push(c);
        }
     }
    }
  }  
  if(topo.size()==n){
  for(auto c:topo)cout<<c<<" ";
  cout<<"\n";
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
 
}