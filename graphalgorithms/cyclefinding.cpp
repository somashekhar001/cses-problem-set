#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long int n,m;cin>>n>>m;
    vector<tuple<long long int,long long int,long long int>>edges(m);
    for(int i=0;i<m;i++){
        long long int x,y,w;
         cin>>x>>y>>w;
         edges[i]=make_tuple(x,y,w);
    } 
    long long int y;
    vector< long long int>p(n+1,-1);
     vector<long long int>dist(n+1,INT_MAX);
 
    for(int i=0;i<n;i++){
        y=-1;
        for(auto x:edges){
             long long int u,v,w;
            tie(u,v,w)=x;
           
             if(dist[v]>dist[u]+w){
                long long int  l=INT_MIN;
              dist[v]=max(l,dist[u]+w);
              y=v;
              p[v]=u;
             }
        }
    }
 
    if(y==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<long long int>path;
        for(int i=0;i<n;i++){
            y=p[y];  
        }
        for(int cur=y;;cur=p[cur]){
            path.push_back(cur);
            if(cur==y && path.size()>1)break;
        }
        reverse(path.begin(),path.end());
        for(auto c:path)cout<<c<<" ";
        
    }
    return 0;
}