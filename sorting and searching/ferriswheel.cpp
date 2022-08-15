#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    long long n,x,c,min=0,max=0;
    cin>>n>>x;
    vector<long long >v;
    vector<long long >m;
    vector<long long >b;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    
     c=x/2;
     for(int i=0;i<n;i++)
     {
         if(v[i]<=c)
         {
             m.push_back(v[i]);
             min++;
         }
         else
         {
             b.push_back(v[i]);
             max++;
         }
     }
     int j=0;
     if(max==n)
     {
         cout<<n<<endl;
         return 0;
     }
     for(int i=0;i<max;i++)
     {
         if(b[max-1-i]+m[j]<=x && min>0 )
         {
             j++;
             min--;
         }
     }
     if(min%2==0)
     {
       cout<<min/2 + max <<endl;
     }
     else
     {
        cout<<min/2 + max +1<<endl;
     }
    
    return 0;
}