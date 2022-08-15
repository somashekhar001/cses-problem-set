#include<bits/stdc++.h>
using namespace std;
class task
{
  public:
   long long dur,dead,ans;
   void insert(long long x,long long y)
   {
       dur=x;
       dead=y;
   }
};
bool cmp(task a,task b)
{
    return a.dur < b.dur ;
}
int main()
{
    task t[200000];
    long long n,sum=0,ans=0;
    cin>>n;
    long long x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        t[i].insert(x,y);
    }
    sort(t,t+n,cmp);
    for(int i=0;i<n;i++)
    {
        long long temp=0;
        temp=sum+t[i].dur;
        sum=temp;
        ans=ans+t[i].dead-sum;
    }
    cout<<ans<<endl;
    return 0;
}