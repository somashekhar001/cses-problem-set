#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long int a=i*i,b=a*(a-1)/2;
        if(i>2){
            b -= 4*(i-1)*(i-2);
        } 
        cout<<b<<endl;
    }
     return 0;
}