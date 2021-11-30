#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*int main(){
    char c[1000]="ccoooodddding";
    int i=1,j=0;
    while(c[i]!='\0'){
    if(c[i]==c[j]){
        c[j]='#';
    }
    i++;j++;
    }
    for(int k=0;c[k]!='\0';k++){
        if(c[k]!='#'){
            cout<<c[k];
        }
    }
    //cout<<c;
    return 0;
}*/
int main(){
    char c[1000]="coooding";
    //cin>>c;
    int j=0;
    for(int i=1;i<strlen(c);i++){
        if(c[i]!=c[j]){
            j++;
            c[j]=c[i];
        }
    
    }
    c[j+1]='\0';
    cout<<c;
    return 0;
}