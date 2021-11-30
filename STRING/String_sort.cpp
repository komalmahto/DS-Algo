#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
 bool compare(string a,string b){
     int mx=(a.length()>b.length())?a.length():b.length();
     //a=aa 87 b=ab;86 a b
    if(int(a[0])<int(b[0])){
          return true;
    }
    else if(int(a[0])==int(b[0])){
        int i=0,j=0;
       while(a[i]==b[j]){
           i++;j++;
           if(a[i]!=b[j]){
               if(a[i]<b[j])
               return false;
           }
       } 
    }
    
    return false;
}
int main(){
    int n=6;
    string colour[n]={"aabb","aaabc","bat","apple","app","batman"};
    vector<string>vec;
    set<string>str;
    /*for(int i=0;i<n;i++){
        cin>>colour[i];
    }*/
    //sort(colour,colour+n);
    sort(colour,colour+n,compare);
    for(int i=0;i<n;i++){
        cout<<colour[i]<<" ";
    }
    /*for(int i=0;i<n;i++){
        cout<<colour[i];
    }
    int a=65;
    for(int i=0;i<n;i++){
        int j=0;
        int k=colour[i][i];
        while(colour[j][i]==k){
            vec.push_back(colour[j]);
            i=j;
            j++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<vec[i];
    }*/

}