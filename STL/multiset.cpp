/*multiset-> it can store multiple elements that have same elements
stored in a specific->sorted according to internal comparison object
values once inserted cant be modified
associate container - key/value,elements are refered  y their value and not by the index
underlysing implemention is BST */

#include<iostream>
#include<set>
using namespace std;
typedef multiset<int>::iterator It;
int main(){
    int arr[]={10,20,30,20,10,10};
    multiset<int>m(arr,arr+6);
    m.erase(20);
    m.insert(80);
    cout<<m.count(10);
    cout<<endl;
    for(int x:m){
        cout<<x<<" ";
    }
    cout<<endl;
    auto it=m.find(30);
    cout<<(*it);
    cout<<endl;
    pair<It,It>range=m.equal_range(10);

    for(auto It=range.first;It!=range.second;It++){
        cout<<*It<<" ";
    }
    cout<<endl;
    for(auto it=m.lower_bound(10);it!=m.upper_bound(30);it++){
        cout<<*it<<" ";
    }
    return 0;
}