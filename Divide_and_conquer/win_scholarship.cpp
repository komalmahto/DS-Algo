// 5 10 3 1

bool can_get(int stu,int coupon,int c,int extra,int mid){
   int ex=(stu-mid)*extra; 
   coupon+=ex;
   if(mid*c>=coupon)
   return true;
   else
   return false;

}
#include<iostream>
using namespace std;
int main(){
    int stu,coupon,c,extra;
    cin>>stu>>coupon>>c>>extra;
    int s=0,e=stu,ans=-1;
    while(s<=e){
        int mid=(s+e)>>1;
        bool karpaye=can_get(stu,coupon,c,extra,mid);
        if(karpaye){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<ans;
}
