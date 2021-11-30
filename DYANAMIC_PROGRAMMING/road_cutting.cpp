#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int max_profit(int prices[],int n,int dp[]){
if(n<=0)
return 0;
if(dp[n]!=0)
return dp[n];
int ans= INT_MIN;
for(int i=0;i<n;i++){
    int cut=i+1;
    int curr_pro=prices[i]+max_profit(prices,n-cut,dp);
    ans=max(curr_pro,ans);
}
return dp[n]=ans;
}
int max_profit_bottom_up(int prices[],int n){
 int dp[n+1]={0};
 for(int i=0;i<=n;i++){
     int ans=INT_MIN;
     for(int i=0;i<n;i++){
         int cut=i+1;
         int current_ans=prices[i]+dp[i-cut];
         ans=max(ans,current_ans);
     }
     dp[i]=ans;
 } 
 return dp[n]; 
}
int main(){
    int prices[]={1,5,8,9,10,17,17,20};
    int n=sizeof(prices)/sizeof(prices[0]);
    int dp[100]={0};
    cout<<max_profit(prices,n,dp);
    return 0;
}