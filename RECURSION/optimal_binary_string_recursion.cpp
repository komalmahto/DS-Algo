#include<iostream>
using namespace std;

int count_unique(int n){
    if(n==0)
    return 1;
    if(n==-1)
    return 0;
    int c1=count_unique(n-1);
    int c2=count_unique(n-2);
    return c1+c2;
}
int main(){
   int n=4;
   cout<<count_unique(n);
}
