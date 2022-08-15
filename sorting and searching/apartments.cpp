#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   long long int n,m,k;
    cin>>n>>m>>k;
    vector<long long int>a;
    vector<long long int>b;
    int temp,count=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        b.push_back(temp);
    }
    sort(a.begin(),a.end());
     sort(b.begin(),b.end());
     int t=0;
    for(int i=0;i<n;i++)
    {
            if(b[t]>=a[i]-k &&b[t]<=a[i]+k)
            {
                count++;
                t++;
            }
            else if(b[t]<a[i]-k)
            {
                i--;
                t++;
            }
             if(t==m)
            {
                break;
            }
    }
    cout<<count;
    
    return 0;
}