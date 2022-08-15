#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
 
const ll MOD=1000000007;
 
/*void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}*/
void solve()
{
  ll n,x;cin>>n;
   vi a;
   vector<bool>b;
  for(int i=0; i<=n; i++){
  
      a.PB(i);
      b.PB(1);
  }
  int l=0,k=0,r=0;
  for(int i=1;i<=n;i++){
    if(b[i])
    {
      if(k!=0)
      {
        cout<<a[i]<<" ";
        b[i]=0;
        l++;
        k=0;
      }
      else
      {
       k++;
      }
      r++;
    }
    if(i==n)
    {
      if(r!=0)
      {
       i=0;
       r=0;
      }
      else{
        break;
      }
    }
  }
 
  
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //readInputFile();
  solve();
 
 return 0;
}