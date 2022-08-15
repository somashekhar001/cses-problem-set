#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 
struct item {
   ll sum;
};
struct segmenttree{
 
   ll size;
   vector<item>value;
     void init(ll n){
       size=1;;
       while(size<n)size*=2;
     
        value.resize(2*size,{0LL});
      }
      item merge(item a,item b){
        return {a.sum+b.sum};
      }
      void set(ll i,ll v,ll x,ll lx,ll rx){
         
         if(rx-lx ==1){
            value[x].sum=v;
            return;
         }
         ll mid=(lx+rx)/2;
         
         if(i<mid) set(i,v,2*x+1,lx,mid);
 
         else set(i,v,2*x+2,mid,rx);
         
         value[x]=merge(value[2*x+1],value[2*x+2]);
      }
      void set(ll i, ll v){
         set(i,v,0,0,size);
      }
      ll sum(ll l,ll r,ll x,ll lx,ll rx){
 
          if(rx<=l || lx>=r )return 0;
 
          if( lx>=l && rx<=r) return value[x].sum;
          
          ll mid=(lx+rx)/2;
 
          return sum(l,r,2*x+1,lx,mid)+sum(l,r,2*x+2,mid,rx);
 
      }
      ll  sum(ll l,ll r){
        return sum(l,r,0,0,size);
      }
 
 
 
};
 
int main(){
 
     
     ll n,q;cin>>n>>q;
     //vector<ll>a(n);
     segmenttree st;
     st.init(n);
     for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        st.set(i,x);
     }
     //st.build(a);
     while(q--){
        ll op;cin>>op;
        if(op==1){
             ll i,v;cin>>i>>v;
             st.set(i-1,v);
        
        }
        else{
            ll l,r;cin>>l>>r;
 
           cout<<st.sum(l-1,r)<<endl;      
        }
     }
     return 0;
}