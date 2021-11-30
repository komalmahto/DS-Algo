#include <iostream>
#include <cstring>
using namespace std;
int string_to_number(char* s){
   int n=strlen(s);
   if(n==0)
   return 0;
   int d=s[n-1]-'0';
   char k[n-1];
   if(n!=1){
   for(int i=0;i<n-1;i++){ 
       k[i]=s[i];
   }}else{
       k='\0';
   }
   //cout<<k;
   int p=string_to_number(k);
   return (p*10+d);
   //cout<<d;
}

int main(){
    char s[]="1248";
    //int n= strlen(s);
    cout<<string_to_number(s);
    return 0;
}