#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long int n,count=0,m=0,rem,min=1000000007,temp;
    
    cin>>n ;
    while(n!=0)
    {
        m=0;
        temp=n;
        while(temp!=0)
        {
            rem=temp%10;
            m=max(rem,m);
            temp=temp/10;
        }
        
        count++;
        n=n-m;
    }
    
    cout<<count<<"\n";
    return 0;
}