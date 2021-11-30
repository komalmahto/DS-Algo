#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 struct job{
     int profit,time;
     job(int profit,int time){
         this->profit=profit;
         this->time=time;
     }
 };
 bool cmp(struct job a,struct job b){
     return a.profit>b.profit;
 }
void cal_maxProfit(struct job arr[],int n){
sort(arr,arr+n,cmp);
for(int i=0;i<n;i++){
   cout<<arr[i].profit<<" : "<<arr[i].time<<endl;
}
bool slot[n];
int ans[n];
for(int i=0;i<n;i++){
slot[i]=false;
}
for(int i=0;i<n;i++){
    for(int j=min(n,arr[i].time)-1;j>=0;j--)
     if(slot[j]==false){
      ans[j]=arr[i].profit;
      slot[j]=true;
      break;
    }
}
for(int i=0;i<n;i++){
if(slot[i])
cout<<ans[i]<<" ";
}
}
 int main(){
     job arr[]={{100,2},{19,1},{27,2},{25,1},{15,3}};
     int n=sizeof(arr)/sizeof(arr[0]);
     cal_maxProfit(arr,n);
 }