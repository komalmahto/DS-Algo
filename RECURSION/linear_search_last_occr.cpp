#include <iostream>
using namespace std;

int last_occr(int a[],int n,int key){
if(n==0){
    return -1;
}
int i=last_occr(a+1,n-1,key); 
if(i==-1)
{
if(a[0]==key)
 return 0;
else 
return -1;
}
return i+1;
}
int main(){
    int n=11,key=5;
    int a[]={1,2,3,4,5,6,5,5,5,5,5};
    cout<<last_occr(a,n,key);
}
/*
#include<iostream>
using namespace std;
int find_last_occur(int *arr,int n,int key){
	if(n==0)
	return -1;
	int last=find_last_occur(arr,n-1,key);
	if(last==-1){
		if(arr[0]==key)
		return 
	}
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int f;
	cin>>f;
	cout<<find_last_occur(arr,n,f);
	return 0;
}*/