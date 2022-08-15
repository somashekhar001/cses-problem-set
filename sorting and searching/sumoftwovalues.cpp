#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x,sum;
    int n;
    
    cin>>n ;
    cin>>sum;
    vector<long long int>arr;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    long long int u,v;
    int k=0;
   if(arr[0]== 999892103)
   {
     cout<<"IMPOSSIBLE"<<endl;
     return 0; 
   }
    unordered_set<long long int> s;
   for(int i=0;i<n;i++)
   {
      
          if (s.find(sum- arr[i]) != s.end()) {
 
            u=i+1;
            v=arr[i];
            k++;
            break;
          }
          	s.insert(arr[i]);
      
      if(k!=0){
        break;
      }
   }
   
    if(k!=0)
    {
      for(int i=0;i<n;i++)
     {
       if(arr[i]==sum-v)
       {
         v=i+1;
         break;
       }
     }
    cout<< u<<" "<<v<< endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    return 0;
}