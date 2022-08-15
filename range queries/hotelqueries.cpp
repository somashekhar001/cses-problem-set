#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
class segmenttree{
    public:
    ll size;
    ll h;
    vector<ll>value;
    void init(ll n){
        size=1;
        h=n;
        while(size<n)size*=2;
        value.assign(size*2,0);
    }
    void set(ll i,ll v){
        set(i,v,0,0,size);
    }
    void set(ll i,ll v,ll x,ll lx,ll rx){
 
        if(rx-lx==1){
            value[x]-=v;
            return ;
        }
        ll mid=(lx+rx)/2;
        if(i<mid){
           set(i,v,2*x+1,lx,mid);
        }
        else{
           set(i,v,2*x+2,mid,rx);
        }
        value[x]=max(value[2*x+1],value[2*x+2]);
    };
 
    void build(vector<ll>&a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            value[x]=a[lx];
            return ;
        }
        ll mid=(lx+rx)/2;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
       value[x]=max(value[2*x+1],value[2*x+2]);
    }
    void build(vector<ll>&a){
        build(a,0,0,size);
    }
    ll get(ll v,ll x,ll lx,ll rx){
     //   cout<<"rx"<<rx<<" "<<"lx"<<lx<<" "<<endl;
        if(rx-lx==1){
            if(value[x]>=v  &&lx<h){
                return lx;
            }
            else{
                return -1;
            }
        }
        ll mid=(lx+rx)/2;
 
        if(value[x]>=v){
             if(value[2*x+1]>=v){
               return get(v,2*x+1,lx,mid);
             }
             else{
                 return get(v,2*x+2,mid,rx);
             }
        }
        else{
            return -1;
        }
    }  
    ll get(ll v){
        return get(v,0,0,size);
    }
    void show(){
        cout<<"*"<<endl;
        for(auto x:value){
            cout<<x<<" ";
        }
        cout<<"*"<<endl;
    }
 
};
 
int main(){
    segmenttree st;
 
    ll n,m;cin>>n>>m;
        st.init(n);
    vector<ll>a(1<<(64 - __builtin_clz(n)));
    for(int i=0;i<n;i++)cin>>a[i];
 
    st.build(a);
 
    while(m--){
        ll v;cin>>v;
        ll ans=st.get(v);
       //  st.show();
         if(ans!=-1)st.set(ans,v);
        cout<<ans+1<<" ";
      // st.show();
    }
 
 
    return 0;
}