#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool canplacecow(int stalls[],int n,int cow,int min_step){
    int cnt=1;
    int last_cow=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-last_cow>=min_step){
            cnt++;
            last_cow=stalls[i];     
             if(cnt==cow){
            return true;
        }
        }
    }
    return false;
}
int main(){
    int n,cows;
    n=5;cows=3;
    int arr[5]={1,2,4,8,9};
    int l=0;
    int h=arr[n-1]-arr[0];
    int mid;
    int ans=0;
    while(l<=h){
     mid=(l+h)/2;//4
     cout<<"Mid "<<mid<<endl;
     bool cowsRakhPaye = canplacecow(arr,n,cows,mid);
     cout<<"Cows rakh "<<cowsRakhPaye<<endl;
     if(cowsRakhPaye){
         ans=mid;
         l=mid+1;//3
     }
     else{
         h=mid-1;
     }
    }
    cout<<ans;
}