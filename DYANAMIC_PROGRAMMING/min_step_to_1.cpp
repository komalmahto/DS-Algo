//min_step_to_1 
// TOP TO DOWN
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int min_step_to_1(int n,int *dp){
    if(n==1)
    return 0;
    if(dp[n]!=0){
        return dp[n];
    }
    int m1,m2,m3=INT_MAX;
    if(n%3==0){
       m1=min_step_to_1(n/3,dp); 
    }
    if(n%2==0){
       m2=min_step_to_1(n/2,dp); 
    }
    
    m3=min_step_to_1(n-1,dp);
    
    int ans=min(min(m1,m2),m3)+1;
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    int dp[1000]={0};
   cout<< min_step_to_1(n,dp);
   return 0;
}