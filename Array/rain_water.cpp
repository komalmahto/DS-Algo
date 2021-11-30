#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{  int n=12;
   //cin>>n;
    //int a[n];
    int a[n]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    /*for(int i=0;i<n;i++){
        cin>>a[i];
    }*/
    /*int Min{*min_element(a, a+n)};
    if(Min<0)
    {
        for(int i{0};i<n;i++)
       {
           a[i]=a[i]+abs(Min);
        }
        }*/
    int m=n;int b[m],c[m];
    for(int i=0;i<m;i++){
        b[i]=a[i];
    }
    for(int i=0;i<m;i++){
        c[i]=a[i];
    }
    int max=*max_element(a,a+n);
    int min=0;bool flag=true;
  for(int i=0;i<n;i++){
      if(a[i]>=min){
        min=a[i];
        a[i]=min;
      }
      else{
          a[i]=min;
      }
      
  } min=0; max=*max_element(b,b+n);cout<<"max "<<max<<endl;
  for(int i=n-1;i>=0;i--){
      if(b[i]>=min){
        min=b[i];
        b[i]=min;
      }
      else{
          b[i]=min;
      }
  }
  int sum=0;
  for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++){
      cout<<b[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++){
      int x=(b[i]>a[i])?a[i]:b[i];
        sum+=abs(x-c[i]);

    }
    cout<<sum;
    return 0;
}