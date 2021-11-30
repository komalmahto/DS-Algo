#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int arr[64]={0};
  for(int i=0;i<n;i++){
      int num;
      cin>>num;
      int j=0;
      while(num>0){
          int mask=(num&1);
          arr[j]+=mask;
          num=num>>1;
		  j++;
      }
  }  
  int p=1,ans=0;
  for(int i=0;i<64;i++){
      arr[i]%=3;
      ans+=(arr[i]*p);
      p=p<<1;
  }
  cout<<ans;
}