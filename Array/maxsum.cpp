#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[9]={-4,1,3,-2,6,2,-1,-4,-7};
    int max_so_far=0;
    int max_end=0;
    for(int i=0;i<9;i++){
        max_end+=a[i];
        if(max_so_far < max_end){
          max_so_far+=a[i];
        }
        if(max_end<0){
            max_end=0;
        }
       
    }
    cout<<max_so_far;
    return 0;
}