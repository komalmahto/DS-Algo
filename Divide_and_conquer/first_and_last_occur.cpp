#include<iostream>
using namespace std;
int find_index(int *arr,int n,int s,int e,int key){
    int ans=-1;
    while(s<=e){
        int mid=(s+e)>>1;
        if(arr[mid]==key){
         ans=mid;
         e=mid-1;//for first occur
        //  s=mid+1;//for last occur
        }
        else if(arr[mid]<key){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[]={1,2,3,4,4,4,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<find_index(arr,n,0,n-1,4);
}