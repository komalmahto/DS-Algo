#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="aabbbbbbaac";
    map<char,int>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    int maxi=-1;char x;
    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
      if(it.second>maxi){
          x= it.first;
        maxi=it.second;
      }
    }
    cout<<x;
    return 0;
}
