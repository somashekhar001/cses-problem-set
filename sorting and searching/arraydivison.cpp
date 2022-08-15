#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
ll n,k;
vector<ll>a;
bool good(ll mid){
    ll sum=0,count=1;
    for(auto c:a){
        if(c>mid)return 0;
        sum+=c;
        if(sum>mid){
            sum=c;
          count++;
        }
        if(count>k)return 0;
    }
    
    return 1;
 
}
int main(){
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
 
    ll l=0,r=1;
    while(!good(r))r*=2;
 
    while(l+1<r){
        ll mid=(l+r)/2;
        if(good(mid)){
          r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<endl;
    
    return 0;
}