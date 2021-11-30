#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
//10,20,30,40 sum=50
bool try_to_arrange(int books[],int n,int m,int sum){
    int cnt=1,books_read=0;
   for(int i=0;i<n;i++){
        if(books_read+books[i]> sum){
            cnt++;
            books_read=books[i];
            if(cnt>m){
                return false;
            }
        }
        else{
            books_read+=books[i];//10+20
        }
   }
   return true;
}
int main(){
    int n,m;
    n=4,m=2;
    int books[n]={10,20,30,40};
    int l=0,mid,h,s=0;
    h=accumulate(books,books+n,s);
    int ans=h;
   while(l<=h){
        mid=(l+h)/2;
        //cout<<mid<<endl;
        bool canarrange = try_to_arrange(books,n,m,mid);
        //cout<<canarrange<<endl;
        if(canarrange){
            h=mid-1;
            ans=min(ans,mid);
            
        }
        else{
            l=mid+1;
        }
   
}
cout<<"ans is "<<ans;
return 0;
}