#include<iostream>
using namespace std;
int cal_jump(int n,int k){
    if(n==0){
     return 1;
    }
    if(n<0){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=cal_jump(n-i,k);
    }
    return ans;
}
int main(){
    int n=4,k=3;
    cout<<cal_jump(n,k);
}