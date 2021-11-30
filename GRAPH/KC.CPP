#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		cin.get();
		string s1,s2;
	cin>>s1>>s2;
		int i=0;
		while(i<s1.length()){
			if(s1[i]==s2[i]){
				cout<<"0";
			}
			else{
				cout<<"1";
			}
			i++;
		}
      cout<<endl;
	}
	return 0;
}