#include<iostream>
#include <string> 
#include <bits/stdc++.h> 
  
using namespace std;
void mapped_string(string in,string out){
	if(in.length()==0)
	 {cout<<out<<" ";
	  return;
    }
    string s1=in,a1=in,out1=out;
	string first=s1.substr(0,1);
	int n1=stoi(first)-0+'A'-1;
	first=char(n1);
    a1.erase(0,1);
    out1.append(first);
	if(n1>=65 and n1<=74)
	mapped_string(a1,out1);
	if(in.length()>1){
    string s2=in,a2=in,out2=out;
    string second=s2.substr(0,2);
	int n2=stoi(second)-0+'A'-1;
	second=char(n2);
	a2.erase(0,2);
    out2.append(second);
	if(n2>=65 and n2<=97)
	{mapped_string(a2,out2);
	}
	}
}
int main() {
    int input;
	cin>>input;
	string in = to_string(input); 
	string out="";
	mapped_string(in,out);
	return 0;
}


