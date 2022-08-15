#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x,k;
    long long int n,min=1000000007;
    
    cin>>n ;
    vector<pair <long ,long >>pi;
    for(int i=0;i<n;i++){
        long a,b;
        cin>>a>>b;
        pi.push_back({a,1});
        pi.push_back({b+1,-1});
    }
    sort(pi.begin(),pi.end());
    long sum=0,ans=0;
    for(auto c:pi){
        sum+=c.second;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
   
    return 0;
}