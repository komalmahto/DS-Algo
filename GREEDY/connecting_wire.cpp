#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int black[]={1,3,4,7};
    int white[]={2,5,8,8};
    int len;
    for(int i=0;i<4;i++){
        len+=black[i]=white[i];
    }
    cout<<len;
}