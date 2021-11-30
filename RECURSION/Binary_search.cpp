#include <iostream>
using namespace std;

int binary_search(int *a,int l,int h,int key){
    if(h>=l)
    { int mid=(l+h)/2;
     if(a[mid]==key)
       return mid;
    else if(a[mid]<key)
     return binary_search(a,mid+1,h,key);
    else
      return binary_search(a,l,mid-1,key);
    }
    return -1;
    
} 
int main(){
    int n=8;
    int a[n]={1,2,3,4,5,6,7,8};
    int l=0,h=n-1,key=7;
    cout<<binary_search(a,l,h,key);
}