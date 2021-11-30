#include<iostream>
using namespace std;
int bit_at_ith(int n,int i){
    return (n&(1<<i))>0?1:0;
}
int set_ith_bit(int n,int i){
    int mask=1<<i;
    return(n|mask);
    }
void  clear_ith_bit(int &n,int i){
    int mask=~(1<<i);
    n=(n&mask);
}
void update_ith_bit(int &n,int i,int v){
    //clear the ith bit
     clear_ith_bit(n,i);
    //then v<<i and do OR 
     int mask=(v<<i);
     n=(n|mask);

}
void clear_range_of_i_bits(int&n ,int i){
   int mask = (-1<<(i+1));
   n=(n&mask); 
}
void clear_range_of_bits(int &n,int i,int j){
    int l_mask=(~0)<<(i+1);
    // if you want i no of bits on then 2^i-1 which is equal to 1<<i -1;
    int r_mask=(1<<j)-1;
    int mask=l_mask|r_mask;
    n= n&mask;
}
void replace(int n,int m,int i,int j){
    int l_mask=(~0)<<(i+1);
    int r_mask=(1<<j)-1;
    int mask=l_mask|r_mask;
    n=n&mask;
    n=n|(m<<j);
    cout<<n;
}

int main(){
    int n=15,i=3,j=1,m=2;
    //cin>>n;
    //cin>>i;
    //cout<<bit_at_ith(n,i);
    //cout<<set_ith_bit(n,i);
    //clear_ith_bit(n,i);
    //cout<<n;
    // update_ith_bit(n,2,0);
    // update_ith_bit(n,3,1);
    // cout<<n;
    //clear_range_of_i_bits(n,1);
    //clear_range_of_bits(n,i,j);
    replace(n,m,i,j);
    //cout<<n;
    cout<<(~0);

}