#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int* fun(){
    char a[]={1,2,3};
    cout<<a<<endl;
    cout<<"a is" <<a[0]<<endl;
    return a;
}
int main(){
    int *d=fun();
    cout<<"d is"<<d<<endl;
    cout<<d[0];
    /*int b[50];
    int *c=new int[5];
    cout<<sizeof(b)<<endl;
    cout<<sizeof(c);*/
}