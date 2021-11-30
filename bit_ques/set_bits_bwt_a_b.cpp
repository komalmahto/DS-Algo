#include<iostream>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;int ans=0;
        for(int i=a;i<=b;i++){
             int i_cpy=i;
             while(i_cpy>0){
                  ans+=(i_cpy&1);
                  i_cpy=i_cpy>>1;
             }
        }
        cout<<ans<<endl;
    }
}
x = 0.05;
x_old = 100;
x_true = 0.0623776;
iter = 0;
while abs(x_old-x) > 10^-3 && x ~= 0
    x_old = x;
    x = x - (x^3 - 0.165*x^2 + 3.993*10^-4)/(3*x^2 - 0.33*x);
    iter = iter + 1;
    fprintf('Iteration %d: x=%.20f, err=%.20f\n', iter, x, x_true-x);
    pause;
end

