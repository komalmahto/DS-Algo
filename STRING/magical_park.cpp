/*4 4 5 20
. . * .
. # . .
* * . .
. # * * */
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
void magical_park(char arr[][100000],int n,int m,int k,int p,map<char,int>mp){
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(arr[i][j]=='#'){
              break;
          }
         if(j==n-1){
             p+=mp[arr[i][j]];
         }
         else{
             p+=mp[arr[i][j]]-1;
      }
  }
cout<<p;
}
}
int main(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    map<char,int>mp;
     mp['*']=5;
     mp['.']=-2;
     magical_park(arr,n,m,k,p,mp);
     

}
/*4 4 5 20
. . * .
. # . .
* * . .
. # * * */
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
void magical_park(char arr[][10000],int n,int m,int k,int p,map<char,int>mp){
  
}
int main(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            arr[i][j]=num;
        }
    }
    map<char,int>mp;
     mp['*']=5;
     mp['.']=-2;
     for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(arr[i][j]=='#'){
              break;
          }
         if(j==n-1){
             p+=mp[arr[i][j]];
         }
         else{
             p+=mp[arr[i][j]]-1;
      }
  }
cout<<p;
}
     

}


