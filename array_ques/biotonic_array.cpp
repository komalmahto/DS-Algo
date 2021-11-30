#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
// 2
// 6
// 12 4 78 90 45 23
// 4
// 40 30 20 10
        for(int i=1;i<n;i++){
            arr[i-1]=arr[i-1]-arr[i];
        }
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
    }
}