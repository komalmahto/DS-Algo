/*
1
15 8 3
3 8
11 2
8 6
*/

#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t,rw,cl,n;
    cin>>t;
    while(t--){
        cin>>rw>>cl>>n;
        int r[n+2],c[n+2],max_r=0,max_c=0;
        r[0]=0,r[n+1]=rw;
        c[0]=0,c[n+1]=cl;
       for(int i=1;i<=n;i++){
           cin>>r[i]>>c[i];
       }

       sort(r,r+n+2);
       sort(c,c+n+2);
       for(int i=1;i<=n+1;i++){
           cout<<r[i]-r[i-1]<<endl;;
            if(r[i]-r[i-1]-1>max_r){
                max_r=r[i]-r[i-1]-1;
            }
            if(c[i]-c[i-1]-1>max_c){
                max_c=c[i]-c[i-1]-1;
            }
            //cout<<max_r<<max_c<<endl;;
       }
        cout<<max_r*max_c;
    }
}