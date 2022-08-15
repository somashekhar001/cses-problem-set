#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
struct item{
   long long int seg,pref,suf,sum;
};
class segmenttree{
  public:
   ll size;
   vector<item>value;
   void init(ll n){
    size=1;
     while(n>size){
      size*=2;
     }
     value.resize(2*size);
   }
   
   item merge(item a,item b){
 
    ll ans=max(a.seg,b.seg);
 
    return {
      max(ans,a.suf+b.pref),
      max(a.pref,a.sum+b.pref),
      max(b.suf,a.suf+b.sum),
      a.sum+b.sum
    };
   }
 
 
   void build(vector<ll>&a, ll x,ll lx, ll rx){
   
    if(rx-lx == 1){
      if(lx<a.size()){
      if(a[lx]>0){
         value[x]={a[lx],a[lx],a[lx],a[lx]};
      }
      else{
        value[x]={0,0,0,a[lx]};
      }
      }
      else{
        value[x]={0,0,0,0};
      }
        return ;
    }
    
    ll mid=(lx+rx)/2;
    
    build(a,2*x+1,lx,mid);
 
    build(a,2*x+2,mid,rx);
    
    value[x]=merge(value[2*x+1],value[2*x+2]);
   
   }
   void build(vector<ll>&a){
        build(a,0,0,size);     
   }
 
 
 
 
    void set(ll i,ll v, ll x,ll lx, ll rx){
   
    if(rx-lx == 1){
      if(v>0){
         value[x]={v,v,v,v};
      }
      else{
        value[x]={0,0,0,v};
      }
        return ;
    }
    
    ll mid=(lx+rx)/2;
    
    if(i<mid){
      
       set(i,v,2*x+1,lx,mid);
    }
    else
    {
       set(i,v,2*x+2,mid,rx);
    }
    value[x]=merge(value[2*x+1],value[2*x+2]);
   }
   
   void set(ll i,ll v){
   
     set(i,v,0,0,size);
   
   }
   
};
 
 
int main(){
    ll n,m;cin>>n>>m;
    segmenttree st;
    st.init(n);
    vector<ll>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    st.build(a);
    
    while(m--){
      ll i,v;cin>>i>>v;
      st.set(i-1,v);
      cout<<st.value[0].seg<<endl;
    }
  return 0;
} 