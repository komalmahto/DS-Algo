#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
//abs 79 bca 79  aabc 79 aab 79
bool compare(pair<string,int>a,pair<string,int>b){
   if(a.second==b.second){
       if(a.first<b.first){
           return true;
       }
       else{
           return false;
       }
   }
   else{
      if(a.second>b.second){
          return true;
      }
      else return false;
   }
}
int main(){
    int greater_salary,n;
    cin>>greater_salary;
    cin>>n;
    pair<string,int>p[n];
    for(int i=0;i<n;i++){
       cin>> p[i].first;
      cin>>p[i].second;
    }
    
    sort(p,p+n,compare);
  for (auto it:p){
     if(it.second>greater_salary){
          cout<<it.first<<" "<<it.second<<endl;
      }
      
  }
  return 0;
}



