//coin_change_top_down
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n=15;
    int coins[]={5};
    int t=sizeof(coins)/sizeof(int);
    int dp[100]={0};
    for(int i=1;i<=n;i++){
        int ans=INT_MAX;
        for(int j=0;j<t;j++){
             if(i-coins[j]>=0)
               ans=min(ans,dp[i-coins[j]]+1);
     }
     dp[i]=ans;
    }
    cout<<dp[n]; 
    return 0;
}
