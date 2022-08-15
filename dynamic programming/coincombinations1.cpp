#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long int n,x,sum,s=0,m=1000000007;
    
    cin>>n ;
    cin>>sum;
    vector<long long >a;
    long long dp[1000000];
    
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    dp[0]=1;
    for(int j=1;j<=sum;j++)
    {
       x=j;
       dp[x]=0;
      for(int i=0;i<n;i++)
      {
          if(x-a[i]>= 0)
          {
            dp[x]+=dp[x-a[i]];
            dp[x] %=m;
          }
       }
    }
 
     cout<<dp[sum]<<"\n";
 
    return 0;
}