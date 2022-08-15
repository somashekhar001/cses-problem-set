#include<iostream>
#include<vector>
 
 
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x;
    int n;
    
    cin>>n ;
    vector<long long int>arr;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    vector<long long int>s;
     long long int maxsumsofar=arr[0];
     long long int maximumsumendhere=0;
    for(int i=0;i<n;i++){
       
       maximumsumendhere=maximumsumendhere+arr[i];
       if(maximumsumendhere>maxsumsofar)
       {
           maxsumsofar=maximumsumendhere;
       }
       if(maximumsumendhere<0)
       {
           maximumsumendhere=0;
       }
            
      }
    
    cout<< maxsumsofar<< endl;
    return 0;
}