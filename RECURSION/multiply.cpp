#include <iostream>
using namespace std;
int multiply(int n,int m){
if(m==0){
    return 0;
}
return n + multiply(n,--m);
}
int main(){
    int n=5,m=4;
   cout<< multiply(n,m);
    
}