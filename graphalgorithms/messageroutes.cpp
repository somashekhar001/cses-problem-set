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
  
  
   vector<int>dist(n+1,1e9+7);
 
   
    queue<ll> q;
    
    if(dist[1]==1e9+7){
        q.push(1);
       dist[1]=1;
      
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
    
    if(dist[n]!=1e9+7){
        
     cout<<dist[n]<<endl;
     q.push(n);
     B.PB(n);
     while(!q.empty()){
         ll t=q.front();
         q.pop();
         for(auto x:A[t]){
            if(dist[x]==dist[t]-1){
                q.push(x);
                B.PB(x);
                break;
            }
         }
     }
     reverse(B.begin(), B.end());
     for(auto x:B){
         cout<<x<<" ";
     }
     cout<<endl;
 
      
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
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