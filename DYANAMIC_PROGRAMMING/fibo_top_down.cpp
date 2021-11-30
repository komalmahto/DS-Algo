#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int fibbo(int n,int*dp){
if(n==0|| n==1){
    return n;
}
if(dp[n]!=0){
    return dp[n];
}
int ans;
ans=fibbo(n-1,dp)+fibbo(n-2,dp);
return dp[n]=ans;

}
  
int main(){
    int dp[100]={0};
    int n;
    cin>>n;
    cout<<fibbo(n,dp);
    return 0;
}