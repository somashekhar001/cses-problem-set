#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long n,M=1000000007;
    cin>>n;
    vector<long long>k;
    k.push_back(0);
    k.push_back(1);
    k.push_back(2);
    k.push_back(4);
    k.push_back(8);
    k.push_back(16);
    k.push_back(32);
    for(int i=7;i<=n;i++)
    {
        k.push_back(k[i-1]%M+k[i-2]%M+k[i-3]%M+k[i-4]%M+k[i-5]%M+k[i-6]%M);
    }
    cout<<k[n]%M<<endl;
    
    return 0;
}