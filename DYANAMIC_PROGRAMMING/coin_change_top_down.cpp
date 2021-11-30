//coin_change_top_down
#include<iostream>
#include<climits>
using namespace std;
int mincoins(int n,int coins[],int t,int dp[]){
if(n==0)
return 0;
if(dp[n]!=0){
    return dp[n];
}
int ans= INT_MAX;
  for(int i=0;i<t;i++){
      if(n-coins[i]>=0){
      int subpro=mincoins(n-coins[i],coins,t,dp);
      ans=min(ans,subpro)+1;
      }
  }  
  dp[n]=ans;
  cout<<dp[n]<<endl;
  return dp[n];
}
int main(){
    int n=15;
    int coins[]={1,7,10};
    int t=sizeof(coins)/sizeof(int);
    int dp[100]={0};
   cout<< mincoins(n,coins,t,dp);
    return 0;
}