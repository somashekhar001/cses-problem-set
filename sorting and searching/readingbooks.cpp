#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n,sum=0,count=0,x,r,bsum=0;
    cin>>n;
    vector<long long>t;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        t.push_back(x);
    }
    sort(t.begin(),t.end());
    
    for(int i=0;i<n;i++)
    {
        sum=sum+t[i];
    }
    r=n;
    bsum=t[n-1];
    for(int i=0;i<r-1;i++)
    {
         count=count+t[i];
        if(count>bsum)
        {
            break;
        }
    }
    if(bsum>=count)
    {
     sum=sum+bsum-count;
    }
    else
    {
        sum=sum;
    }
    cout<<sum<<endl;
    return 0;
}