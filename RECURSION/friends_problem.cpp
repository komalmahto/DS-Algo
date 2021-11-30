#include<iostream>
using namespace std;
 int to_take_friend(int n){
     if(n==0)
     return 1;
     if(n==-1)
     return 0;
  return  to_take_friend(n-1)+n-1c1*f(n-2);
 }
int main(){
    int n=4;
   cout<< to_take_friend(n);
}