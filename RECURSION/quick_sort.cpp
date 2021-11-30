#include <iostream>
using namespace std;
int partition(int *arr,int s,int e){
    int i=s-1;
    int j=s;
    int p=arr[e];
    for(;j<=e-1;j++){
        if(arr[j]<p){
            i=i+1;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[e],arr[i+1]);
    return i+1;
}
void quick_sort(int *arr,int s,int e){
    if(s>=e)
    return ;
    int p=partition(arr,s,e);
    for(int i=s;i<e;i++){
        cout<<arr[i];
    }cout<<endl;
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);

}
int main(){
    int arr[]={2,7,8,6,1,5,4};
    int n=sizeof(arr)/sizeof(int);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}