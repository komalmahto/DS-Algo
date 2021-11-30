#include<iostream>
using namespace std;
//010
void find(int i,string s){
    
    int j=0;
while(i>0){
    int mask=(i&1);
    if(mask){
    cout<<s[j];
    }
    i=i>>1;
    j++;
}
cout<<endl;
}
void func(string s){
int len=s.size();
for(int i=0;i<(1<<len);i++){
    find(i,s);
}
}
 int main(){
     string s="abc";
     func(s);
 }