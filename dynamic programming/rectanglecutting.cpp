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
void solve()
{
  ll a,b;cin>>a>>b;
  ll dp[a+1][b+1];
  
  for(int i=0;i<=a;i++) {
   for(int j=0;j<=b;j++){
      if(i==j) {
          dp[i][j]=0;
      }
      else{
          dp[i][j]=1e9;
          for(int k=1;k<i;k++){
              dp[i][j]=min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
          }
          for(int k=1;k<j;k++){
              dp[i][j]=min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
          }
      }
      
   }
  }
  cout<<dp[a][b]<<endl;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //readInputFile();
  solve();
 
 return 0;
}