#include<iostream>
using namespace std;
int count_ways(int n){
    if(n<=3){
        return 1;
    }
    return count_ways(n-1)+count_ways(n-4);
}
int main(){
    int n=4;
    cout<<count_ways(n);
}