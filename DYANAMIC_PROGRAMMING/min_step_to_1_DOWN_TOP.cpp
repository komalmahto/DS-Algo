//min_step_to_1 
// DOWN TO TOP
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    
    int n;
    cin>>n;
   int  dp[100]={0};
    dp[1]=0;
    for(int i=2;i<=n;i++){
       int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
       if(i%3==0){
           ans1=dp[i/3];
        }
        if(i%2==0){
           ans2=dp[i/2];
        }
        ans3=dp[i-1];
        dp[i]=min(ans1,min(ans2,ans3))+1;

    }
    /*for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }*/
   cout<< dp[n];
    return 0;
}
