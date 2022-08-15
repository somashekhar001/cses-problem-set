#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  long long n,x=5,b=0;
   cin>>n;
   while(x<=n)
   {
       b=b+n/x;
       x=x*5;
   }
   cout<<b<<endl;
   return 0;
}