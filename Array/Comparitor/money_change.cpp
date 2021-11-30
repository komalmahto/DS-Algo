#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool compare(int a,int b){
    //cout<<a<<" "<<b<<endl;
    return a<=b;
}
int main(){
    int arr[8]={1,2,3,10,20,50,100,200};
    int money=168; int get=0;
    int cpy_money=money;
        while(get!=cpy_money){
        auto it=lower_bound(arr,arr+8,money,compare)-arr;
        if(it){
         cout<<arr[it-1]<<" "<<it-1<<endl;
         get+=arr[it-1];
         //cout<<get<<" ";
         money-=arr[it-1];
        }
         
         }

    return 0;
}