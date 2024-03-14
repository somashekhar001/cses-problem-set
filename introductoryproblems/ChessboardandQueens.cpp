#include<bits/stdc++.h>

using namespace std;

struct point{
    int open=1;
    int diag_up=0;
    int diag_down=0;
    int right=0;
};
//It is a generalised solution for any nxn matrix and placing n queens change n in down line if you want to experiment 

//solution :
/*
  idea : traverse each column recursively and store the next column possibilities in a vector of points(defined using struct)

  points: if(open) means allowed to keep queen else you cant keep
          update values of diag_up,open,diag_down,right,when you are keeping queens so they can track of previously kept queens effect

*/
int n=8;
int ans=0;
void solve(int j, vector<vector<int>>&matrix,vector<point>column){

    if(j==n){
        ans++;
        return ;
    }
    int sum=0;
   
    for(int col=0;col<n;col++){
       
       if(matrix[col][j] && column[col].open){
           point p;
           vector<point>next_col(n,p);
          
          
           for(int i=0;i<n;i++){
                
                 if(column[i].right==1){
                     next_col[i].open=0;
                 
                     next_col[i].right=1;
                 
                 }
                 if(column[i].diag_down==1){
                    if(i+1<n){
                     next_col[i+1].open=0;
                     next_col[i+1].diag_down=1;
                    
                    }
                 }
                 if(column[i].diag_up==1){
                    if(i-1>=0){
                     next_col[i-1].open=0;
                     next_col[i-1].diag_up=1;
                    }
                 }
              
           }

           next_col[col].open=0;
           if(col+1<n){
               next_col[col+1].diag_down=1;
                 next_col[col+1].open=0;
           }next_col[col].right=1;

           if(col-1>=0){
                 next_col[col-1].open=0;
               next_col[col-1].diag_up=1;
           }
            solve(j+1,matrix,next_col);
       }

    }
   
    return ;
}

int main(){
    vector<string>input(n);
    vector<vector<int>>matrix(n,vector<int>(n,1));
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(input[i][j]=='*') matrix[i][j]=0;
      }
    }
    point p;
    vector<point>column(n,p);
    solve(0,matrix,column);
    cout<<ans<<"\n";

    return 0;
}