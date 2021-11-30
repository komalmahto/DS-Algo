#include<iostream>
#include<map>
using namespace std;
//CUMULTIVE SUM BANAO AND CHECK KARO K (SUM - CUM) SUM KYA MAAP M H.
//AGR H TO (I-M[PRE-SUM]) VARNA AGR ZERO HO R CUMM SUM THEN I+1;
// 10 2 -2 -20 10
// 10 12 10 -10 0
int len_sum_k(int *arr,int n,int k){
    int pre=0;int len=0;
    int ct=0;
    map<int,int>m;
    for(int i=0;i<n;i++){
        pre+=arr[i]; 
        if(pre-k==0){
           len=max(len,i+1);//4
           ct++;
        }
        else if(m.find(pre-k)!=m.end()){
           len=max(len,i-m[pre-k]);
           ct++;
        }
            m[pre]=i;

    }
    return ct;
}
//  10 -2
//  12- 1

int main(){
    int arr[5]={10,2,-2,-20,10};
    cout<<len_sum_k(arr,5,-10);
}
