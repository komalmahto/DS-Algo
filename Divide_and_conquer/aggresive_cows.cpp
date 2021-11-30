
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool can_place(int *stalls,int cows,int n,int min_steps){
    int last_cow=stalls[0];int ct=1;
    for(int i=1;i<n;i++){
    if(stalls[i]-last_cow>=min_steps){
        last_cow=stalls[i];
        ct++;
     if(ct==cows){
         return true;
     }
    }
}
return false;
}

int main(){
int stalls[]={1,2,4,8,9};
int cows=3;
int n=5;
int s=0; 
int ans=0;
int e=stalls[n-1]-stalls[0];
while(s<=e){
    int mid= (s+e)/2;
    bool cowsrakhpae=can_place(stalls,cows,n,mid);
    if(cowsrakhpae){
        ans=mid;
        s=mid+1;
    }else{
        e=mid-1;
    }
}
cout<<ans;
}