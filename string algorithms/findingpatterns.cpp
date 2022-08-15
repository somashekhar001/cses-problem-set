#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int 
 void count_sort(vector<ll> &p,vector<ll> &c){
    ll n=p.size();
   
     vector<ll>cnt(n);
    for(auto x:c){
        cnt[x]++;
    }
    vector<ll> new_a(n);
    vector<ll>pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++){
        pos[i]=pos[i-1]+cnt[i-1];
    }
    for(auto x:p){
        ll i=c[x];
        new_a[pos[i]]=x;
        pos[i]++;
    }
    p=new_a;
   
 
 }
int main(){
    ll n;
    string s;cin>>s;
    s+='$';
    n=s.size();
 
    vector<ll>p(n),c(n);
   { //k=0;
    vector<pair<char,ll>>a(n);
    for(int i=0;i<n;i++){
        a[i]={s[i],i};
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        p[i]=a[i].second;
    }  
   
    c[p[0]]=0;
    for(int i=1;i<n;i++){
        if(a[i].first==a[i-1].first){
            c[p[i]]=c[p[i-1]];
        }
        else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
   }
    ll k=0;
 
    while((1<<k)<n){
    
        for(int i=0;i<n;i++){
           p[i]=(p[i]-(1<<k)+n)%n;
        }
        count_sort(p,c);
       
    vector<ll>c_new(n);
    c_new[p[0]]=0;
    for(int i=1;i<n;i++){
        pair<ll,ll> now={c[p[i]],c[(p[i]+(1<<k))%n]};
        pair<ll,ll> prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
        if(now==prev){
            c_new[p[i]]=c_new[p[i-1]];
        }
        else{
            c_new[p[i]]=c_new[p[i-1]]+1;
        }
    }
      c=c_new;
       k++;
    }
   
    ll q;cin>>q;
   
    while(q--){
        string t;cin>>t;
        
       ll len =t.size();
       
    
        bool b=false;
        ll l=0,r=n;
        while(l+1<r){
            ll mid=(l+r)/2;
            b=true;
           for(int i=0;i<len;i++){
            if(s[p[mid]+i]<t[i]){
                l=mid;
                b=false;
                break;
            }
            else if(s[p[mid]+i]>t[i]){
                r=mid;
                b=false;
                break;
            }
           }
           if(b)break;
        }
        if(b)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}