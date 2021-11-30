#include <iostream>
using namespace std;
//1,2,6,9,5
void merge(int *a,int l,int h){
   // cout<<a[l]<<a[h]<<endl;
    int mid=(l+h)/2;
    int i=l;
    int j=mid+1;
    int k=l;
    int temp[100];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
            }
        else{
            temp[k++]=a[j++];
            }
    }
    for(;i<=mid;i++){
        temp[k++]=a[i];
    }
    for(;j<=h;j++){
        temp[k++]=a[j];
    }
    for(int i=l;i<=h;i++){
        a[i]=temp[i];
    }
}
void merge_sort(int a[],int l,int h){
if(l>=h)
return;
int mid=(l+h)/2; 

 merge_sort(a,l,mid);

 merge_sort(a,mid+1,h);
 merge(a,l,h);
}
int main(){
    int a[]={1,2,6,5,9};
    int l=0,n=5;
    merge_sort(a,l,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
