#include<iostream>
#include<stack>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000005
void SieveOfEratosthenes(vector<int>& primes)
{
	bool IsPrime[MAX_SIZE];
	memset(IsPrime, true, sizeof(IsPrime));

	for (int p = 2; p * p < MAX_SIZE; p++) {
		if (IsPrime[p] == true) {
			for (int i = p * p; i < MAX_SIZE; i += p)
				IsPrime[i] = false;
		}
	}
	for (int p = 2; p < MAX_SIZE; p++)
		if (IsPrime[p])
			primes.push_back(p);
}


void playing_with_cards(int *arr,int n,int q){
//5 1
//3 4 7 6 5
vector<int> primes;
SieveOfEratosthenes(primes);
for(int k=1;k<=q;k++){
    stack<int>s1;
    stack<int>s2;
    int ith_prime=primes[k-1];
   for(int i=n-1;i>=0;i--){
    if(arr[i]%ith_prime==0){
        s1.push(arr[i]);
    }else{
        s2.push(arr[i]);
    }
}
while(!s1.empty()){
    cout<<s1.top()<<endl;
    s1.pop();
}

while(!s2.empty()){
    cout<<s2.top()<<endl;
    s2.pop();
}
}
}
int main(){
    int n,q;
    cin>>n>>q;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   playing_with_cards(arr,n,q);
  
}
