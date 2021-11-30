#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void readLine(char c[],int maxlen){
    int i=0;
    char ch=cin.get();cout<<ch<<endl;
    while(ch!='\n'){
        c[i]=ch;
        i++;
        if(i==(maxlen-1)){
            break;
        }
        ch=cin.get();
    }
    c[i]='\0';
    return;
}
int main(){
    char a[1000];
    readLine(a,1000);
    return 0;
}