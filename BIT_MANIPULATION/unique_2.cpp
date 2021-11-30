#include<iostream>
using namespace std;
void find_unique(int *arr,int n){
    int res=0,i=0;
    while(i<n){
        res=res^arr[i];
        i++;
    }
    int res_cpy=res;
    int pos=0;
    //cout<<res;
    while(res_cpy>0){
        if((res_cpy&1)==1)
        break;
        res_cpy=res_cpy>>1;
        pos++;
    }
    int mask=(1<<pos);
    int x=0;
    for(int i=0;i<n;i++){
     if((mask&arr[i])>0){
         x=x^arr[i];
     }
    }
    cout<<x<<" "<<(x^res);
    //cout<<pos;
}
int main(){
    int arr[]={5,1,2,1,2,3,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    //find_unique(arr,n);
    cout<<(1^1^1);
}