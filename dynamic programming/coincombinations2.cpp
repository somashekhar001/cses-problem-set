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
 
void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  
  ll n,x,sum;
  cin>>n>>sum;
  ll a[n];
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  ll dp[1000000];
 
  dp[0]=1;
  for(int i=0; i<=sum;i++)
  {
      dp[i]=0;
  }    
  dp[0]=1;
  for (int k = 1; k <= n; k++) 
  {
     for (int x =a[k-1]; x <= sum ; x++)
     {
         if(x-a[k-1]>=0)
         {
          dp[x]=dp[x]%MOD+dp[x-a[k-1]]%MOD;
          dp[x]%=MOD;
         }
     }
    
  }
  cout<<dp[sum]%MOD<<"\n";
 return 0;
}