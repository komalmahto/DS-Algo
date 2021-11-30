#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main(){
    string c ="puuu issssssssssssssssssssssssssssssssssssssssssssssss laangoooooo";
    int count_far=0,count_end=0;string a_far="",a_end="";
    for(int i=0;i<c.length();i++){
         if(c[i] ==' '){
              
            if(a_end.length()<a_far.length())
                {a_end=a_far;}
         if(count_end<count_far){
             count_end=count_far;
             
             
         }
         count_far=0;
         a_far="";
        }
        else{
              a_far+=c[i];
              count_far++;
        }
    } 
    if(count_end<count_far){
    count_end=count_far;
    cout<<a_far<<" "<<count_end;
    }
    cout<<"Largest String is "<<a_end<<" and length is "<<count_end;
}