#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool can_allo(int * books,int n,int stu,int min_page){
int last=0,ct=1;
for(int i=0;i<n;i++){
    if(books[i]+last>min_page){
      ct++;
      last=books[i];
      if(ct>stu)
      return false;
    }
    last+=books[i];
}
return true;

}

int main(){
    int books[]={10,20,30,40};
    int n=sizeof(books)/sizeof(books[0]);
    int stu=2;
    int s=books[n-1];
    int e=0;int ans=INT_MAX;
    e=accumulate(books,books+n,e);
    while(s<=e){
        int mid=(s+e)>>1;
        bool karpaye=can_allo(books,n,stu,mid);
        if(karpaye){
            ans=min(ans,mid);
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
cout<< ans;
}