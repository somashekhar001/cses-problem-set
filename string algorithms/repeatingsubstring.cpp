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
      /*  for(auto c:p){
            cout<<c<<" ";
        }
        cout<<endl;
       */k=0;
 
       vector<ll>lcp(n);
        for(int i=0;i<n-1;i++){
            ll pi=c[i];
            ll j=p[pi-1];
          //cout<<pi<<" "<<j<<endl;
            while(s[i+k]==s[j+k])k++;
 
            lcp[pi]=k;
          
            k=max(0LL,k-1);
        }
        /*for(int i=1;i<n;i++){
            cout<<lcp[i]<<" ";
        }
        cout<<endl;
          */ 
          ll i=0,x=-1,sum=0;
          for(auto c:lcp){
            if(sum<c){
              sum=c;
              x=i;
            }
            i++;
          }
          if(x==-1){
            cout<<-1<<endl;
            return 0;
          }
          string ans=s.substr(p[x],n-p[x]);
          for(int i=0;i<sum;i++){
            cout<<ans[i];
          }        
          cout<<endl;
        
        return 0;
    }