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
 
bool inside(int x,int y,int m,int n){
    if(x>=0 && y>=0 && x<n && y<m){
        return true;
    }
    return false;
}
 
 
 
void solve(){
 
  ll n,m;cin>>n>>m;
  vector<string>s;
  string x;
 
  for(int i=0;i<n;i++){
      cin>>x;
      s.PB(x);
  }
 
 
vector<vector<vector<pi>>>adj(n,vector<vector<pi>>(m,vector<pi>(0,pi({0,0}))));
vector<pi>neigh({{0,1},{0,-1},{1,0},{-1,0}});
pi l,k;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(s[i][j]=='.' || s[i][j]=='A' || s[i][j]=='B'){
            for(auto c:neigh){
                ll x=i+c.first;
                ll y=j+c.second;
                if(inside(x,y,m,n) && (s[x][y]=='.' ||  s[x][y]=='A' || s[x][y]=='B')){
                    adj[i][j].PB({x,y});
                    adj[x][y].PB({i,j});
                }
            }
            if(s[i][j]=='A'){
                l={i,j};
            }
            if(s[i][j]=='B'){
                k={i,j};
            }
        }
    }
}
 
vector<vector<int>>dist(n,vector<int>(m,INT_MAX)); 
 
queue<pi>q;
 
q.push(l);
dist[l.first][l.second]=0;
while(!q.empty()){
  pi d=q.front();
  ll x=d.first;
  ll y=d.second;
 
  q.pop();
  for(auto h:adj[x][y]){
    if(dist[h.first][h.second]>dist[x][y]+1){
        dist[h.first][h.second]=dist[x][y]+1;
        q.push(h);
    }
  }
}
ll ans=dist[k.first][k.second];
if(ans!=INT_MAX){
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    vector<char>sol;
    q.push(k);
    while(!q.empty()){
        pi d=q.front();
        ll x=d.first;
        ll y=d.second;
        q.pop();
        pi min=d;
        for(auto c:adj[x][y]){
           if(dist[c.first][c.second]<dist[min.first][min.second]){
            min=c;
           } 
        }
        if(min!=d) q.push(min);
       
        ll xdif=x-min.first;
        ll ydif=y-min.second;
        if(xdif== 0 && ydif == 0){
            break;
        }
        else if(xdif==0 && ydif==1){
             sol.PB('R');
        }
        else if(xdif==0 && ydif==-1){
             sol.PB('L');
        }
        else if(xdif==1 && ydif==0){
              sol.PB('D');
        }
        else if(xdif==-1 && ydif==0){
            sol.PB('U');
        }
    }
    reverse(sol.begin(),sol.end());
    for(auto x:sol)cout<<x;
     
     cout<<endl;
}
else{
    cout<<"NO"<<endl;
}
 
 
}
int main()
 {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
 
 return 0;
}