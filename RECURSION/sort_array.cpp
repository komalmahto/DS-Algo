#include <iostream>
using namespace std;
int * is_sorted(int *arr,int n){
    if(n==0 || n==1){
        return arr;
    }
    if(arr[0]<arr[1] && is_sorted(arr+1,n-1)){
        return arr;
    }
    if(arr[0]>arr[1]){
    int temp=arr[0];
    arr[0]=arr[1];
    arr[1]=temp;
    is_sorted(arr+1,n-1);
    }
    return arr;
}
int main(){
    int arr[7]={1,2,3,9,5,8,4};
    is_sorted(arr,7);
    for(int i=0;i<7;i++)
    cout<<arr[i];
}