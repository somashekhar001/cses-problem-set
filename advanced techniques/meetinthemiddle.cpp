#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
int main(){
    ll n,s;
    cin>>n>>s;
 
    ll lena=n/2;
    ll lenb=n-n/2;
         vector<ll>a(lena);
          vector<ll>x(1<<lena);
    for(int i=0;i<lena;i++){
        cin>>a[i];
    }
        vector<ll>b((lenb));
         vector<ll>y(1<<lenb);
    for(int j=0;j<lenb;j++){
        cin>>b[j];
    }
    ll cnt=0;
    for(ll mask=0;mask<(1<<lena);mask++){
        ll sum=0;
        for(ll i=0;i<lena;i++){
            if(mask & (1<<i)){
                sum+=a[i];
            }
        }
        x[mask]=sum;
    }
     for(ll mask=0;mask<(1<<lenb);mask++){
        ll sum=0;
        for(ll i=0;i<lenb;i++){
            if(mask & (1<<i)){
                sum+=b[i];
            }
        }
        y[mask]=sum;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(ll i=0;i<x.size();i++){
        
       auto low=lower_bound(y.begin(),y.end(),s-x[i]);
       auto high=upper_bound(y.begin(),y.end(),s-x[i]);
       
       ll l=low-y.begin();
       ll r=high-y.begin();
 
       cnt+=r-l;
    }
 
    cout<<cnt<<endl;
    return 0;
}