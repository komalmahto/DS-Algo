#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int main(){
     int a[6]={16,17,4,3,5,2};
     int max=a[5];a[5]=-1; 
     for(int i=4;i>=0;i--){
         int x=a[i];
         a[i]=max;
         if(max<x){
             max=x;
         }
         
     }
      for(int i=0;i<6;i++){
         cout<<a[i];
     }
 }