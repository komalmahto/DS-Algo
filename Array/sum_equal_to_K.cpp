#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//only for sorted array two pointer appraoch
int main(){
    int n=10;int num=9;
    int a[n]={1,2,3,4,5,6,7,8,9,12};
    int p=0,q=n-1;
    while(p< q){
        if(a[p]+a[q]==num){
            cout<<"Found at index "<<p<<" "<<q<<endl;
            p++;q--;
            
        }
        else if(a[p]+a[q]>num){
            q--;
        }
        else{
            p--;
        }
    }
}