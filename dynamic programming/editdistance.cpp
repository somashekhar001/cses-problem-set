#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
 
ll MOD=1000000007;
 
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  // freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  string a,b;
  cin>>a>>b;
  ll m=a.size(),n=b.size();
  ll dp[m+1][n+1];
  
 
  for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
         if(i==0 || j==0){
             dp[i][j]=i+j;
            continue;
         }
         if(a[i-1]==b[j-1]){
            dp[i][j]=dp[i-1][j-1];
         }
         else{
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
         }
      }
  }
  ll lcs=dp[m][n];
  cout<<lcs<<endl; 
  return 0;
}