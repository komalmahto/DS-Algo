#include <iostream>
using namespace std;
int all_occur(int *arr,int i,int j,int n,int key,int *out){
if(i==n){
    return j;
}
if(arr[i]==key){
    out[j++]=i++;
    return all_occur(arr,i,j,n,key,out);
}else{
    i++;
    return all_occur(arr,i,j,n,key,out);
}
}
int main(){
    int arr[]={1,2,5,3,5,5,6,5,5};
    int out[10000]; int n=9,key=9,i=0,j=0;
    int c=all_occur(arr,i,j,n,key,out);
    cout<<c<<endl;
    for(int k=0;k<c;k++){
        cout<<out[k];
    }
}