#include <iostream>
using namespace std;
int main(){
    int n=7;
    int arr[n]={1,2,3,7,3,1,2};
    int i,ans=0;
    for(i=0;i<n;i++){
        ans=ans^arr[i];
    }
    cout<<ans;
    cout<<(7^6);
    cout<<(7&1);//1 hence oddd
    cout<<(6&1);//0 hence even
}