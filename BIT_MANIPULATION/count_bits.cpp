#include<iostream>
using namespace std;
int count_bits_1(int n){
    int ans=0;
    while(n>0){ 
    ans+=(n&1);
    n=n>>1;
    }
    
    return ans;
}
int count_bits_2(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main(){
    int n=5;
    cout<<count_bits_1(n);
    cout<< __builtin_popcount(n);
}