#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long count=1,max=0;
  string s;
  cin>>s;
  for(int i=0;s[i] != '\0';i++)
  {
   if(s[i]==s[i+1])
   {
       count++;
   }
   else
   {
       if(max<=count)
       {
           max=count;
       }
       count=1;
   }
 
  }
  if(count>=max)
  {
      max=count;
  }
 
   cout<<max<<endl;
    return 0;
}