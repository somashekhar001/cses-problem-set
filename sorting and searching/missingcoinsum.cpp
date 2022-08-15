#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    vector<long long int>v;
    int n;
    cin>>n;
    long long int x;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }                                                     
    sort(v.begin(), v.end());
    long long int missingSum=0;
   for(int i=0; i<n; i++)
   {
       if(missingSum+1<v[i])
       {
           break;
       }
      missingSum=missingSum+v[i];
   }
    cout<<missingSum+1<<endl;
    return 0;
}