#include <iostream>
using namespace std;
void deci_to_binary(int n){
    int p=1,ans=0;
    while(n>0){
        int last_bit= (n&1);
        ans+=p*last_bit;
       p=p*10;
       n=n>>1;
    }
    cout<<ans;
}
int main(){
    int n=13;
    deci_to_binary(n);
    return 0;
}