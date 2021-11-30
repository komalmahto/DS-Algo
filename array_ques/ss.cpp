#include<iostream>
using namespace std;

int main(){
    int tg;
    cin>>tg;
    string s;
    cin>>s;
    int ct_a=0,ct_b=0;int i=0,j=0; // aabbba 2
    for(int k=0;k<s.length();k++){
         if(s[k]=='a')
         ct_a++;
         if(s[k]=='b')
         ct_b++;
         if(min(ct_a,ct_b)<=tg)
         i++;
         if(min(ct_a,ct_b)>tg)
         {  if(s[j]=='a')
             ct_a--;
             else ct_b--;
             j++;
         }
     }


}