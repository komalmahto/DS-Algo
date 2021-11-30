#include<iostream>
#include<set>
using namespace std;
int main(){
    /*set<int>s;
    int arr[]={1,1,2,3,4,4,5,6,7,0,-2,-3};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    auto it=s.find(4);
    s.erase(it);
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;*/
    set<pair<int,int>>st;
    st.insert(make_pair(5,1));
    st.insert(make_pair(5,2));
    st.insert(make_pair(7,3));
    auto it=st.lower_bound(make_pair(20,5));
    cout<<it->first<<" "<<it->second;
    for(auto x:st){
        cout<<x.first<<" "<<x.second<<endl;
    }


}