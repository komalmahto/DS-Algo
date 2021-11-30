#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int x,int y){
return x>y;
}
//,bool (&cm)(int a,int y)
void bubble_sort(int a[],int n,bool (&cm)(int a,int y)){
    for(int i=1;i<n;i++){
        for(int j=0;j<=(n-i-1);j++){
            if(cm(a[j],a[j+1])){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    int a[5]={6,8,2,10,1};
    bubble_sort(a,5,compare);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}