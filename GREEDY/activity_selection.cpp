/*3
3
3 9
2 8
6 9
*/
#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
bool compare (pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int main(){
int t,n,s,e;
cin>>t;
while(t--){
cin>>n;
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
    cin>>s>>e;
    v.push_back(make_pair(s,e));
}
/*for(auto i:v){
    cout<<i.first<<" "<<i.second<<endl;
}*/
//ACTIVITY SELECTION ALGORITHM
sort(v.begin(),v.end(),compare);
int res=1;
int fin=v[0].second;
for(int i=1;i<n;i++){
    if(v[i].first>=fin){
        res++;
        fin=v[i].second;
    }
}
cout<<res<<endl;
v.clear();
}
}