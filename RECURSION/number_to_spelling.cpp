#include <iostream>
using namespace std;
string spelling[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
 void number_to_spelling(int n){
     if(n==0){
         return;
     }
     number_to_spelling(n/10);
     int digit=n%10;
     cout<<spelling[digit]<<endl;
 }
int main(){
    int n=2048;
    number_to_spelling(n);
}