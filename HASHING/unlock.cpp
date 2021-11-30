/*#include<iostream>
#include<map>
#include<vector>
using namespace std;
bool is_sorted(vector<pair<int,int>>m,int n){
   for(int i=0;i<n-1;i++){
	   if(m[i+1].first>m[i].first)
	   return false;
   }
   return true;
}
int main() {
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>>m;
	for(int i=0;i<n;i++){
        int num;
		cin>>num;
		m.push_back(make_pair(num,i));
	}
	/*vector<pair<int,int>>::iterator it;
	for( it=m.begin();it!=m.end();it++){
		cout<<it->first<<" -> "<<it->second<<endl;
	}
	int j=0,i=n-1;
	while(i>=0){
		if(m[i].second!=j and m[j].first<m[i].first){
			cout<<m[i].first<<endl;;
		  m[i].second=j;
		  m[j].second=i;
		  swap(m[i],m[j]);
		  k--;
		  if(is_sorted(m,n)){
			  break;
		  }
		  if(k==0)
		  break;
		  }
		  j++;
	}
	for(int i=0;i<n;i++){
		cout<<m[i].first;
	}
	return 0;
}
/*#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
	map<int,int>m1;
	map<int,int>m2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        int num;
		cin>>num;
		m1[num]++;
	}
	for(int i=0;i<n;i++){
        int num;
		cin>>num;
		m2[num]++;
	}
	vector<int>vec;
	map<int,int>:: iterator it;
	for(it=m1.begin();it!=m1.end();it++){
		if(m2.find(it->first)!=m2.end()){
			while(it->second--){
				vec.push_back(it->first);
			}
		}
	}
	return 0;
}*/
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	unordered_map<int,int>m;
	int arr[n];
	for(int i=0;i<n;i++){
        int num;
		cin>>num;
		cin>>arr[i];
		m.insert(make_pair(num,i));
	}
	sort(arr,arr+n);
	auto it=m.begin();
	for(int i=0;i<n;i++){
		int temp=m[arr[i]];
		m[arr[i]]=i;
		it->second=temp;
		cout<<temp<<" ";
		k--;
		it++;
		if(k==0)
		break;
	}
	for(auto i:m){
		cout<<i.first<<" -> "<<i.second<<endl;
	}
}

#include <iostream>
using namespace std;
void displaySubset(int subSet[], int size) 
{ 
for(int i = 0; i < size; i++)
{
cout << subSet[i] << " ";
}
cout << endl;
}

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum) {
if( total == sum)
{ 
displaySubset(subSet, subSize);
subsetSum(set,subSet,n,subSize-1,total- set[nodeCount],nodeCount+1,sum);
return;
}
else {
for( int i = nodeCount; i < n; i++ )
{ subSet[subSize] = set[i];
subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum);
}
}
}
void findSubset(int set[], int size, int sum)
{ int *subSet = new int[size];
 subsetSum(set, subSet, size, 0, 0, 0, sum); 
 delete[] subSet;
}
int main() {
int weights[] = {10, 7, 5, 18, 12, 20, 15};	// The Set int size = 7;
findSubset(weights, size, 35);	// The Sum Value = 35

}
