#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int make_change(int *a,int money,int n){
    int ans=0;
    while(money>0)
    { int idx= upper_bound(a,a+n,money)-1-a;
        cout<<a[idx]<<" ";
        money=money-a[idx];
        ans++;
    }
    cout<<endl;
    return ans;
}
int main(){
    int money=39;
    int change[]={1,2,5,10,20,50,100,200,500,1000,2000};
    int n=sizeof(change)/sizeof(int);
    cout<<make_change(change,money,n);
}