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
 
/*void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}*/
void solve(){
  ll n,m;cin>>n>>m;
 
  vector<int>A[n+1];
  vector<int>B;
 
  for(int i=0;i<m;i++){
      ll u,v;
      cin>>u>>v; 
      A[u].PB(v);
      A[v].PB(u);
  }
  ll count=0;
   vector<int>dist(n+1,1e9+7);
  for(int i=1; i<=n; i++){
    
   
    queue<ll> q;
    
    if(dist[i]==1e9+7){
        q.push(i);
        B.PB(i);
       dist[i]=1;
       count++;
    }
 
    while(!q.empty()){
        ll t=q.front();
        q.pop();
 
        for(auto x:A[t]){
            if(dist[x]==1e9+7){
                 q.push(x);
                 dist[x]=dist[t]+1;
            }
        }
 
    }
    
  }
  cout<<count-1<<endl;
  for(int i=0;i<count-1;i++){
      cout<<B[i]<<" "<<B[i+1]<<endl;
  }
  cout<<endl;
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