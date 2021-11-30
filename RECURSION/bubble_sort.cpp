#include <iostream>
using namespace std;

void bubble_sort(int *a,int j,int n){
    if(n==1)
    return;
    if(j==n-1){
    return bubble_sort(a,0,n-1);
    }
    if(a[j]>a[j+1])
    {swap(a[j],a[j+1]);
    }
    return bubble_sort(a,j+1,n);
    
}
int main(){
    int a[]={5,4,3,2,1};
    bubble_sort(a,0,5);
    for(int i=0;i<5;i++){
        cout<<a[i];
    }
}