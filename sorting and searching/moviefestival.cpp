#include <bits/stdc++.h>
 
class movie
{
    public:
    int start, end,interval;
    void insert(int start,int end)
    {
        this->start=start;
        this->end=end;
        this->interval=this->end-this->start;
    }
};
bool cmp(class movie a, class movie b)
{
    a.end>b.end;
    return a.end<b.end ;
}
using namespace std;
int main()
{
    movie M[20000000];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    int n;
    cin>>n ;
    for(int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        M[i].insert(x,y);
    }
    sort(M,M+n,cmp);
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(M[i].end<=M[i+1].start)
        {
            count++;
        }
        else
        {
            M[i+1]=M[i];
        }
    }
    cout<<count<<endl;
    
    return 0;
}