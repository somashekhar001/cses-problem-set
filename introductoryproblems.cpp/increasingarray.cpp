#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long n,x,temp=0;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x); 
    }
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1]<v[i])
        {
          temp=temp+v[i]-v[i+1];
          v[i+1]=v[i];
        }
    }
    cout<<temp<<endl;
    return 0;
}