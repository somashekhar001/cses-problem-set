#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;cin>>q;

    while(q--){
        
        long long int k,ans=0;
        cin>>k;
        long long int val=9,digit=1,cnt=0;

        while(ans + (val*digit) <= k) {
            ans += (val*digit);   
            cnt+=(val);
            val *= 10;
            digit++;  
        }

        k-=ans;
     
        cnt+=(k/digit);
      
        int rem = k%digit;

        if(rem==0){
            cout<<cnt%10<<"\n";
        }
        else {
            cnt++;
            digit-=rem;
            while(digit--){
                cnt/=10;
            }
            cout<<cnt%10<<"\n";
        }


    }
    return 0;
}