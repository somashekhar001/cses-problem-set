#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n,M=1000000007;
    char x;
    cin>>n;
    long long dp[n][n],arr[n][n],k=0;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x;
            arr[i][j]=x;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[0][i]=='*')
        {
            dp[0][i]=0;
            k++;
        }
        else
        {
            if(k==0)
            {
             dp[0][i]=1;
            }
            else
            {
             dp[0][i]=0;
            }
        }
    }
    k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]=='*')
        {
            dp[i][0]=0;
            k++;
        }
        else
        {
            if(k==0)
            {
               dp[i][0]=1;
            }
            else
            {
               dp[i][0]=0;
            }
        }
    }
   
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[i][j]=='*')
            {
              dp[i][j]=0;        
            }
            else
            {
             dp[i][j]=(dp[i-1][j]%M+dp[i][j-1]%M)%M;
            }
                
        }
    }
    cout<<dp[n-1][n-1]%M<<endl;
    return 0;
}