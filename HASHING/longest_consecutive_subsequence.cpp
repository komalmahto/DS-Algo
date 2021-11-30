#include<iostream>
#include<unordered_set>
using namespace std;
int longest_consecutive_subsequence(int *a,int n){
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    int len1=0,len2=0;
    for(int i=0;i<n;i++){
        
        if(s.find(a[i]-1)==s.end()){
            
            int next_no=a[i]+1;len2=0;
            while(s.find(next_no)!=s.end()){
                //cout<<next_no<<" ";
                next_no+=1;
                len2++;
            }
            cout<<len2<<endl;
            len1=max(len1,len2);
            //cout<<"len "<<len1<<endl;
        }
        
    }
    return len1;
}
//14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10
int main(){
    int a[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<longest_consecutive_subsequence(a,n);
}