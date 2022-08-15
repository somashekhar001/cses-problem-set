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
  
  /*freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);*/
  
  ll n,x,sum=0;
  cin>>n;
  vi a;
  for(int i=0; i<n; i++)
  {
    cin>>x;
    a.PB(x);
    sum=sum+x;
  }
  bool dp[sum+1];
 
  for(int i=0; i<=sum; i++)
   {
    dp[i]=false;
   }  
 
   dp[0] = true;
 
  for (int k = 1; k <= n; k++) 
  {
     for (int x = sum-a[k-1]; x >= 0; x--)
     {
          dp[x+a[k-1]] |= dp[x];
     }
  }
  ll count=0;
  for(int i=1;i<=sum;i++)
  {
      if(dp[i])
      {
         count++;
      }       
  }
  cout<<count<<endl;
  for(int i=1;i<=sum;i++)
  {
      if(dp[i])
      {
         cout<<i<<" ";
      }       
  }
  cout<<"\n";
 
 return 0;
}