#include <iostream>
using namespace std;
int linear_search(int *arr,int key){
    if(arr[0]==key){
       return 0; 
    }
   int i=linear_search(arr+1,key);
   if(i==-1){
       return -1;
   }
    return i+1;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int key=6;
    cout<<linear_search(arr,key);
}