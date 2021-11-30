#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    //int a[3][4]={{1,4,7,10},{2,5,8,11},{3,6,9,12}};
    
for(int j=0;j<n;j++){
if(j%2==0){
for(int i=0;i<m;i++){
    cout<<a[i][j]<<" ";
}}
else{
for(int i=m-1;i>=0;i--){ 
cout<<a[i][j]<<" ";
          }
          
    }
}
}
 /*00 01 02 03
 10 11 12 13
 20 21 22 23*/