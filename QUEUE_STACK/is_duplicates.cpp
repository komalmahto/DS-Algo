#include<iostream>
#include<stack>
using namespace std;
//()
bool is_duplicate(string s){
	stack<char>st;
	int i=0,j=0; 
	for(int k=0;k<s.size();k++){
        bool flag=false;
		if(s[k]=='('){
			st.push(s[k]);
		}
		else if(s[k]==')'){
           if(!st.empty()){
               while(st.top()!='('){
                   st.pop();
                   flag=true;
               }
               if(st.top()=='(' and flag){
                   st.pop();
               }
           }
		    //st.pop();
		}else{
            st.push(s[i]);
		}
	}
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return st.empty();
}
int main() {
	string s;
	getline(cin,s);
	if(is_duplicate(s)){
		cout<<"Duplicate";
	}else{
		cout<<"Not Duplicates";
	}
	return 0;
}