#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
 
const ll MOD=1000000007;
ll n,m;
 
  vector<ll>A[100001];
  ll start;
  ll en;
  vector<bool>vis;
  vector<ll>parent;
/*void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}*/
bool dfs(int i,int par){
   vis[i]=true;
   for(auto x:A[i]){
     if(par==x){
       continue;
     }
     if(vis[x]){
        start=x;
        en=i;
        return true;
     }
     parent[x]=i;
     if(dfs(x,parent[x])){
       return true;
     }
   }
   return false;
}
void solve(){
  cin>>n>>m;
  parent.assign(n+1,-1);
  vis.assign(n+1,false);
  start=-1;
  
  for(int i=0;i<m;i++){
      ll u,v;
      cin>>u>>v; 
      A[u].PB(v);
      A[v].PB(u);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i] && dfs(i,parent[i])){
      break;
    }
  }
  if(start==-1){
    cout<<"IMPOSSIBLE"<<endl;
  }
  else{
    vector<int>cycle;
  cycle.PB(start);
  for(int i=en;i!=start;i=parent[i]){
    cycle.PB(i);
  }
  cycle.PB(start);
  reverse(cycle.begin(),cycle.end());
  cout<<cycle.size()<<endl;
  for(auto x:cycle){cout<<x<<" ";}
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // readInputFile();
  solve();
 
 return 0;
}