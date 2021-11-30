#include <iostream>
using namespace std;
int clearBits_I_to_J(int n,int i,int j){
int mask1=((~0)<<(i+1)); 
int mask2=(1<<j)-1;   
int cleared=mask1|mask2;
return (n&cleared);

}
// 0001 || 0100    1111
int main(){
    int n=15,i=3,j=1;
    int m=2;
    int x=clearBits_I_to_J(n,i,j); 
    int y=(m<<j);
    cout<<(x|y);
    return 0;
}