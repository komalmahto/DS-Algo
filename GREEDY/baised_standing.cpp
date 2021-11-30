/*
1
7
komal 1
rohan 2
sonam 2
shourya 1
sonu 5
sachin 7
kajal 7
*/
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<string,int>p1,pair<string,int>p2){
    return p1.second<p2.second;
}
int main(){
    int t,n,rank;
    string name;
    cin>>t;
    while(t--){
       vector<pair<string,int>>vec;
       cin>>n;
       for(int i=0;i<n;i++){
        cin>>name>>rank;
        vec.push_back(make_pair(name,rank));
       }
       
       sort(vec.begin(),vec.end(),compare);
       for(auto it:vec){
           cout<<it.second<<endl;
       }
       int res=0;int j=1;
       for(auto i:vec){
           res+=abs(i.second-j);
           j++;
       }
       cout<<res;
    }
}