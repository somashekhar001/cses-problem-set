#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x,sum;
    long long int n,s=0;
    
    cin>>n ;
 
    long long int count=0;
    vector<long long int>arr;
    map<long long int,long long int>map;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    map[s]=1;
    long  rem;
    for(int i=0;i<n;i++){
         s=s+arr[i];
         rem=s%n;
         if(rem<0)rem+=n;
         count+=map[rem];
         map[rem]++;
    }
    cout<<count<<endl;
    return 0;
}