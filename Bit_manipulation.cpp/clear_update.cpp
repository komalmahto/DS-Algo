#include <iostream>
using namespace std;

bool check_odd(int n){
    if(n&1)
    return true;
    return false;
}
int bit_at_particular_index(int n,int i){
   int mask= 1<<i; //101 100
   return (n & mask)>0?1:0;
   }
int to_set_bit(int n,int i){
    //101 010
    int mask=1<<i;
    return (n|mask);
}
int clear_bit(int n,int i){
  //101&110 = 100
  int mask=~(1<<i);
  return (n&mask);
}
int update_bit(int n,int i,int v){
   // 111
   int mask=~(1<<i);//100 ~-> 011
   cout<<mask<<endl;
   int cleared_bit= (n&mask);// 111&011->011
   cout<<cleared_bit<<endl;
   return (cleared_bit|(v<<i));//011|000
}
int clear_bit_till_i(int n,int i){
    int mask=(-1<<i);//1111&1100
    return (n&mask);
}
int clear_bit_i_to_j(int n,int i,int j){
    int mask1=(-1<<(i+1));
    cout<<mask1<<endl;//11111->1000016+8+4+2+1
    int mask2=(1<<j)-1;
    //00011
    return (mask1|mask2);
}
int main(){
 int n=31,i=3,j=2;
 //cout<<check_odd(n);
 //cout<<bit_at_particular_index(n,i);
 //cout<<to_set_bit(n,i);
 //cout<<clear_bit(n,i);
 //cout<<(0<<2)<<endl;
 //cout<<~(1<<2)<<endl;
//cout<<update_bit(n,i,0);
//cout<<clear_bit_till_i(n,i);
cout<<clear_bit_i_to_j(n,i,j);
//cout<<(1<<4)<<endl;
 return 0;
}