#include <iostream>
using namespace std;
void all_subsequence(char* in, char*out, int i,int j){
if(in[i]=='\0'){
    out[j]='\0';
    cout<<out<<" ";
    return;
}
out[j]=in[i];
all_subsequence(in,out,i+1,j+1);
//out[j]='\0';
all_subsequence(in,out,i+1,j);
}
int main(){
    char a[]="abc";
    char output[100];
    all_subsequence(a,output,0,0);
return 0;
}