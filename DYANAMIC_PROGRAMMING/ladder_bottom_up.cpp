#include<iostream>
using namespace std;
int ladder_down_top(int n,int k,int *dp){
for(int i=1;i<=n;i++){
    int ans=0;
    for(int j=i;j>=i-k;j--){
        if(j>=0)
        ans+=dp[j];
    }
    dp[i]=ans;
}
return dp[n];
}
int optimised_ladder_down_top(int n,int k,int*dp){
    int win=0,count=1;
    int sum=dp[0];
    for(int i=1;i<=n;i++){
         if(count==k)
          {dp[i]=sum;
          sum=sum-dp[win];
          sum+=dp[i];
          win++;}
         else{
             dp[i]=sum;
         sum+=dp[i];
         count++;
         }
         
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];
}
int main(){
    int n=5,k=3;
    int dp[100]={0};
    dp[0]=1;
    cout<<optimised_ladder_down_top(n,k,dp);
    return 0;
}