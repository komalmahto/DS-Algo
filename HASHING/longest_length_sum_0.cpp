#include<iostream>
#include<unordered_map>
using namespace std;
int lon_len_subarray_sum_zero(int *arr,int n){
  unordered_map<int,int>m;
  int pre=0;int len=0,l;
  for(int i=0;i<n;i++){
      pre+=arr[i];
      if(pre==0){
          len=max(len,i+1);
      }
      if(m.find(pre)!=m.end()){
          len=max(len,i-m[pre]);
      }
     else{
         m[pre]=i;
      }
  }
  return len;
}
int main(){
    int arr[]={1,2,3,5,-2,-6};
    int n=sizeof(arr)/sizeof(int);
    cout<<lon_len_subarray_sum_zero(arr,n);
    return 0;
}