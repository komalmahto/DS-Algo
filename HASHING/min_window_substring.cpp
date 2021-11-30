/*#include<iostream>
#include<unordered_map>
#include <climits>
using namespace std;
//FIND THE SMALLEST WINDOW IN A STRING CONTAINING ALL CHARACTERS OF ANOTHER STRING
// s -hellloeeo world
// a -eelo
string smallest_window(string s,string a){
    int big=s.length();
    int tny=a.length();
    if(big<tny) return "NONE"; 
    unordered_map<int,int>bg;
    unordered_map<int,int>ty;
    for(int i=0;i<tny;i++)
        ty[a[i]]++;
    
    int count=0,start=0,min_len=INT_MAX,start_idx=-1;
   for(int i=0;i<big;i++){
       bg[s[i]]++;
       if(ty.find(s[i])!=ty.end() and bg[s[i]]<=ty[s[i]]){
           count++;
       }
       if(count==tny){
            int temp=s[start];
           while(ty.find(temp)==ty.end() or bg[temp]>ty[temp]){
                   bg[temp]--;
                   start++;
                   temp=s[start];
           }
           int min_2=i-start;
          if(min_2<min_len){
              min_len=min_2+1;
              start_idx=start;
          }}}
   if(start_idx==-1) return "NONE";
string ans=s.substr(start_idx,min_len);
return ans;
}
int main(){
    string s="hellloeeo world";
    string a="eelo";
    cout<<smallest_window(s,a);
    return 0;
}*/
#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;
string string_window(string s1,string s2){
	int l1=s1.length();
	int l2=s2.length();
	unordered_map<int,int>m1;
	unordered_map<int,int>m2;
	for(int i=0;i<l2;i++){
		m2[s2[i]]++;
	}

	int start=0,count=0,len=INT_MAX,start_idx=-1;
	for(int i=0;i<l1;i++){
		m1[s1[i]]++;
		if( m2.find(s1[i])!=m2.end() and m1[s1[i]]<=m2[s1[i]]){
			count++;
		}
		if(count==l2){
			int temp=s1[start];
			while(m2.find(temp)==m2.end() or m1[temp]>m2[temp]){
				m1[temp]--;
				start++;
				temp=s1[start];
			}
			int min_len=i-start;
			if(min_len<len){
				len=min_len+1;
				start_idx=start;
			}
		}
		
	}
	string ans=s1.substr(start_idx,len);
		return ans;
}
int main() {
	string s1="hellloeeo world",s2="eelo";
	
	cout<<string_window(s1,s2);
	return 0;
}
#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	unordered_set<int>mp; int ans=0,j=0;
	for(int i=0;i<n;i++){
		while(j<n and mp.find(arr[j])==mp.end()){
			mp.insert(arr[j]);
			j++;
		}
		ans+=((j-i+1)*(j-i+2))/2;
		mp.erase(arr[i]);
	}
	cout<<ans;
	return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;

string min_window(string s,string pattern)
{
    
    if (s.length()<pattern.length())
        return "NONE";
    int s_freq[256]{0},pattern_freq[256]{0};
   int min_window{s.length()};
    for(int i=0;i<pattern.length();i++)
    {
         pattern_freq[pattern[i]]++;
        }
        int count{0};
        int start{0},start_idx{-1};
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        s_freq[ch]++;
        if(pattern_freq[ch]!=0 and pattern_freq[ch]<=s_freq[ch])
        {
            count++;
            }
            
        if(count== pattern.length())
        {
            char temp=s[start];
            while(pattern_freq[temp]==0 or s_freq[temp]>pattern_freq[temp] )
            {
                s_freq[temp]--;
                start++;
                temp=s[start];
                }
                
            int window_length=i-start; 
            if(window_length<min_window)
            {
                min_window=window_length;
                start_idx=start;
                }
            }
        }
        if(start_idx==-1)
        {
            return "NONE";
            }
        string ans=s.substr(start_idx,min_window);
        
        return ans;
    }

int main()
{
    
    cout<<min_window("samardeep","sama")<<endl;
    return 0;
    
    }*/