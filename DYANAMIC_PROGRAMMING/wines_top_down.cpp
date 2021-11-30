#include<iostream>
#include<climits>
using namespace std;
int max_profit(int *arr,int i,int j,int y,int dp[][100]){
if(i>j)
return 0;
if(dp[i][j]!=0)
return dp[i][j];
int pr1=arr[i]*y+max_profit(arr,i+1,j,y+1,dp);
int pr2=arr[j]*y+max_profit(arr,i,j-1,y+1,dp);
return dp[i][j]=max(pr1,pr2);
}

int main(){
    int arr[]={2,3,5,1,4};
    int y=1;
   int dp[100][100]={0};
   int n=sizeof(arr)/sizeof(arr[0]);
   int i=0,j=n-1;
   cout<<max_profit(arr,i,j,y,dp);


}