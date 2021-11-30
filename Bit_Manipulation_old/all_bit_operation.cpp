#include <iostream>
using namespace std;

 
/*bool check_odd (int n)
{
  
if (n & 1)
    
return true;
  
return false;

}


int
bit_at_particular_index (int n, int i)
{
  
int mask = 1 << i;		//101 100
  return (n & mask) > 0 ? 1 : 0;

}


int to_set_bit (int n, int i)
{
  
    //101 010
  int mask = 1 << i;
  
return (n | mask);

}


int clear_bit (int n, int i)
{
//101&110 = 100
int mask = ~(1 << i);
return (n & mask);
}
int update_bit (int n, int i, int v)
{
  int mask=~(1<<i);
  int cleared_bit=n&mask;
  int mask2=v<<i;
  return (cleared_bit|mask2);       
}

int clear_bit_till_i (int n, int i)
{ //1111&1100
int mask = (-1 << i);	
return (n & mask);
}


int clear_bit_i_to_j (int n, int i, int j)
{
  int mask1=((~0)<<(i));
  int mask2=(1<<j)-1;
  int cleared=mask1|mask2;
  return (n&cleared);

}
*/

int main ()
{
 int a, b, c;
  a = 2, b = 6, c = 8;
if((c & a & b) < (b & c))
    {
      c = (12 & 6) + a;
      cout<<"HII";
    }
cout<<a + b + c ;
int num=12, i;
    for (i = 1; i <= num; ++i) {
        if (num % i == 0) {
            i=i+3;
        }
    }
    cout<<i;
    
/*int n = 31, i = 4, j = 1;
  
    //cout<<check_odd(n);
    //cout<<bit_at_particular_index(n,i);
    //cout<<to_set_bit(n,i);
     //cout<<clear_bit(n,i); //11111 16+8+2+1 
    //cout<<(0<<2)<<endl;
    //cout<<~(1<<2)<<endl;
//cout<<update_bit(n,i,1);
//cout<<clear_bit_till_i(n,i);
cout << clear_bit_i_to_j (n, i, j);//19
  
//cout<<(1<<2)<<endl;*/
    return 0;

}


