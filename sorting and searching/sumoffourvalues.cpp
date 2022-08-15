#include <bits/stdc++.h>
 
using namespace std;
int main()
{
   
    long long int x,sum;
    int n;
    
    cin>>n ;
    cin>>sum;
    vector<long long int>arr;
    vector<long long int>v;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(arr[i]);
    }
    sort(arr.begin(),arr.end());
    long long int u,z,w,b;
    int m=0;
  for(int j=0;j<n;j++)
   {
       int currentsum=sum-arr[j];
    for(int i=j+1;i<n-2;i++)
    {
       int l=i+1;
        int r=n-1;
        while(l<r){
            if(arr[l]+arr[r]+arr[i]==currentsum)
            {
               u=arr[l];
               z=arr[i];
               w=arr[r];
               b=arr[j];
               m++;
              
               break;
            }
            else if(arr[l]+arr[r]+arr[i]<currentsum)
            {
                l++;
            }
            else
            {
                r--;
            }
                
        }
        if(m!=0)
        {
            break;
        }
    }
   }
    int l=0,t=0,r=0,s=0;
    if(m!=0)
    {
     for(int i=0;i<n;i++)
     {
        if(v[i]==u && l==0)
        {
            
            u=i;
            l++;
        }
        else if(v[i]==z && t==0)
        {
            z=i;
            t++;
        }
        
        else if(v[i]==w && r==0)
        {
            w=i;
            r++;
        }
        else if(v[i]==b && s==0)
        {
            b=i;
            s++;
        }
        
     }
      cout<<u+1<<" "<<z+1<<" "<<w+1<<" "<<b+1<<endl;
    }
    else
    {
     cout<<"IMPOSSIBLE"<<endl;
    }
 
    return 0;
}