#include<iostream>
using namespace std;

void next_greater(int *a,int n,int *b){
for(int i=0;i<n;i++){
    bool flag=false;
      int j=(i+1)%n;//2
     while(j!=i)
     { 
       if(a[i]<a[j]){
          b[i]=a[j];
          flag=true;
          break;
     }  j=(j+1)%n;
    }
if(!flag){
         b[i]=-1;
     }
     }
     for(int i=0;i<n;i++){
        cout<<b[i];
    }

}

int main(){
    /*int n;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }*/
    int n=3;
    //int *a=new int[n];
    int *b=new int[n];
    int a[3]={1,3,2};
  next_greater(a,n,b);
    
}