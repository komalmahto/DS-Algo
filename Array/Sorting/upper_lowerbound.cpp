#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n[5]={1,2,3,3,4};
    auto it=lower_bound(n,n+5,3)-n;
    auto it1=lower_bound(n,n+5,3+1)-n;
    cout<<it1-1<<" "<<it;


    return 0;

}