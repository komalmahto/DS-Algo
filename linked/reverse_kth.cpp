/*#include<iostream> 
using namespace std;
class node{
 
 public:
 int data;
 node*next;
 node(int data){
	 this->data=data;
	 next=nullptr;
 }
};
node*s=nullptr;
void reverse(node*p,int k){
	
    node*start=p;
    node* j=p;
    node*new_head=0;
    node*r=nullptr;
    node*q=nullptr;
    int l=k;
    while(p and l--){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    new_head=q;
    int k_cpy=k;
    while(p){
    r=q=0;
    j=p;
    while(p and k--){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    k=k_cpy;
    start->next=q;
    start=j;
    }
    start->next=nullptr;
    while(new_head){
        cout<<new_head->data<<" ";
        new_head=new_head->next;
    }
}
int main(){
	int n,k;
	cin>>n>>k;
	node*head;

	node*p=new node(-1);
	head=p;
	for(int i=0;i<9;i++){
		int num;
		cin>>num;
		node* temp=new node(num);
		p->next=temp;
		p=p->next;
	}
	node*q=nullptr;
	p=head->next;
	node*e=p;
    
	   reverse(p,k);
	  
	
}

#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node*next;
	node(int data){
		this->data=data;
		next=nullptr;
	}
};
void append(node* p,int k){
	node*head=p;
	node*q=p;
	while(p and k--){
	  p=p->next;
	}
	while(p->next){
		q=q->next;
		p=p->next;
	}
	p->next=head;
	p=head;
	head=q->next;
	q->next=nullptr;
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main() {
	int n,k;
	cin>>n;
	node*p=new node(-1);
	node*head=p;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		node*temp=new node(num);
		p->next=temp;
		p=p->next;
	}
	cin>>k;
	append(head->next,k);
	return 0;
}
*/
#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

string diff_in_ascii(string s,int n,int i){
	for(int i=0;i<=2*n-1;i+=2){
     int diff=s[i+1]-s[i];
	string d=to_string(diff);
    //cout<<d;
	s.insert(i+1,d);
    }
return s;
}
int main() {
	string s="abcxd";
	//getline(cin,s);
	int i=0;
	cout<<diff_in_ascii(s,s.length(),i);
	return 0;
}