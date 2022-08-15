#include <bits/stdc++.h>
using namespace std;
 
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  long long int n,x,min,b=0;
   cin>>n;
   std::vector<long long int >v; 
    vector<long long int>ans;
   for(int i=0;i<n;i++)
   {
       cin>>x;
       v.push_back(x);
   }
   
   stack<pair<long long int,long long int>> st;
   for(int i=0;i<n;i++)
   {
      while(!st.empty() && v[i]<=st.top().first){
        st.pop();
      }
      if(!st.empty()){
       ans.push_back(st.top().second);
      }
      else
      {
        ans.push_back(0);
      }
      st.push({v[i],i+1});
   }
   for(int i=0;i<n;i++)
   {
       cout<<ans[i]<<" ";
   }
   cout<<"\n";
   return 0;
}