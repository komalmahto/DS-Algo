#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
    int s1=0,n;
    cin>>n;
    int arr[n];
    int max_far=0,max_end=INT_MIN;
    int min_far=0,min_end=INT_MAX;
    for(int i=0;i<n;i++){
         s1+=arr[i];
        max_far+=arr[i];
        if(max_end<max_far)
        max_end=max_far;
        if (max_far<0)
          max_far=0;

       min_far+=arr[i];
       if(min_end>min_far)
       min_end=min_far;

       if(min_far>0)
        min_far=0;
    }
    //cout<<s1<<" "<<min_end<<" "<<max_end<<endl;
    min_end=s1-min_end;
    if(min_end==0){
        cout<<max_end;
    }
    else{
        if(max_end>min_end)
        {
        cout<<max_end;
        }
    else{
        cout<<min_end;
    }}
    //cout<<max_end<<" "<<min_end;
    cout<<endl;
    }
    return 0;
}