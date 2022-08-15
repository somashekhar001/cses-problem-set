#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x,sum;
    long long int n,s=0;
    
    cin>>n ;
    cin>>sum;
    long long int count=0;
    vector<long long int>arr;
    map<long long int,long long int>map;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    map[s]=1;
    for(int i=0;i<n;i++){
         s=s+arr[i];
        if(map.find(s-sum) != map.end())
        {
            count+=map[s-sum];
        }
         map[s]++;
    }
    cout<<count<<endl;
    return 0;
}