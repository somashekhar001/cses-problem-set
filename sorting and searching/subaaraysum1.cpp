#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
int main(){
    ll n,x;cin>>n>>x;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    ll count=0,l=0,sum=0;
    for(ll r=0;r<n;r++){
        sum+=a[r];
        while(sum>x){
            sum-=a[l];
            l++;
        }
        if(sum==x){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}