#include<bits/stdc++.h>
using namespace std;
 
 
 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
 
const ll MOD=1000000007;
void solve(){
   ll n,q;
   cin>>n>>q;
   vi a;
   ll x;
   ll c,d;
   for(int i=0;i<n;i++){
       cin>>x;
       a.PB(x);
   }
    ll s[n];
     s[-1]=0;
   for(int i=0; i<n ;i++){
       s[i]=a[i]+s[i-1];
   }
    
    ll ans[q];
    for(int i=0;i<q;i++)
   {
       cin>>c>>d;      
       x=s[d-1]-s[c-2];
       ans[i]=x;
   }
   for(int i=0;i<q ;i++){
       cout<<ans[i]<<endl;
   }
  
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  solve();
 
 return 0;
}