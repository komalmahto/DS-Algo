#include <iostream>
using namespace std;

int count_set_bits(int n){
    int ans=0;
    while(n>0){
       ans+=n&1;
       n=n>>1;
    }
    return ans;
}
int main(){
    int n=15;
    cout<<count_set_bits(n);
    cout<<_builtin_popcount(n);
    return 0;
}