#include<iostream>
using namespace std;
int cal_jump(int n,int k,int *dp){
    if(n==0){
     return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=cal_jump(n-i,k,dp);
    }
    return dp[n]=ans;
}
int main(){
    int n=4,k=3;int dp[100]={0};
    cout<<cal_jump(n,k,dp);
}