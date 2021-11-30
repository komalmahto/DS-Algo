// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1
#include<iostream>
#include<cmath>
using namespace std;
bool can_make(int *arr,int n,int s,int e,int min_time){
    int ct=0;int sum=0;
    for(int i=0;i<n;i++){
        for(int j=1;i<=min_time;j++)
          {
              sum+=arr[i]*j;
              ct++;
              if(ct>=n)
              return true;
          }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>p;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int s=0;int ans=-1;
        int e= (n/2)*(arr[0]+(n-1)*arr[0]);
        while(s<=e){
            int mid=(s+e)>>1;
            bool banpaye=can_make(arr,n,s,e,mid);
            if(banpaye){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        cout<<ans;
    }
}