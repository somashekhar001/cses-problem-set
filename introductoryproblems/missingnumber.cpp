#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long n,x;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        v.push_back(x); 
    }
    sort(v.begin(),v.end());
    int i;
    for(i=0;i<n-1;i++)
    {
        if(v[i] != i+1)
        {
            cout<<i+1<<endl;
            break;
        }
 
    }
    if(i==n-1)
    {
       cout<<i+1<<endl;
    }
    
    return 0;
}