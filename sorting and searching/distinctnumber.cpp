#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int N;
    vector<int>a;
    int count=1;
    cin>>N;
    int temp;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    
    int first=a[0];
    for(int j=1;j<N;j++)
    {
        if(first!=a[j])
        {
           count++;
           first=a[j];
        }
        
    }
    cout<<count;
    return 0;
}