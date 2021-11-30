#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void count_steps(int n){
    if(n%2==0){
        cout<<1;
    }else{
        int n=log(n)/log(2);
        int num=pow(2,n);
        int rem=(n-num);
        cout<<(1+rem);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        count_steps(n);
    }
}