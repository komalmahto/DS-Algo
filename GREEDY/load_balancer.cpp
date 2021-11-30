/*8
16 17 15 0 20 1 1 2
23
*/
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0;
    s=accumulate(arr,arr+n,s);
    //cout<<s<<endl;; //0 6 10 0
    int load=s/n;int min_load= INT_MIN,l; int s1=0;
    for(int i=0;i<n-1;i++){
        s1+=arr[i];
        l=(i+1)*load;
         min_load=max(abs(l-s1),min_load);
        
    }
    cout<<min_load;
}