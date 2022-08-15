#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n,k,ans,x;
    cin>>n>>k;
    vector<long long>t;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        t.push_back(x);
    }
    sort(t.begin(),t.end());
    long long l=0,r=k*t[0];
    while(l<=r)
    {
        long long mid=(l+r)/2;
        long long sum=0;
        
      for(int i=0;i<n;i++)
      {
         sum=sum+(mid/t[i]);  
         if(sum>=k)
         {
             break;
         }
      }
      if(sum>=k)
      {
          ans=mid;
          r=mid-1;
      }
      else
      {
          l=mid+1;
      }
    }
    cout<<ans<<endl;
    return 0;
}