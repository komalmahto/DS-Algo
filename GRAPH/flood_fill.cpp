#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void flood_fill(int graph[][6],int i,int j,int rep,int neww){
if(i<0 ||j<0 || i>=8 ||j>=6)
return;
if(graph[i][j]!=rep)
return;
graph[i][j]=neww;
for(int k=0;k<4;k++){
    flood_fill(graph,i+dx[k],j+dy[k],rep,neww);
}

}
int  main(){
    int graph[8][6]={ 1,1,1,1,1,1,
                        1,2,2,2,2,1,
                        1,2,1,1,2,1,
                        1,2,1,1,2,1,
                        1,2,1,1,2,1,
                        1,2,1,1,2,1,
                        1,2,2,2,2,1,
                        1,1,1,1,1,1,
                     };
    int i=0,j=1,rep=1,neww=0;
    flood_fill(graph,i,j,rep, neww);
    for(int i=0;i<8;i++){
        for(int j=0;j<=6;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}
// 0000000
// 0222200
// 0211200
// 0211200
// 0211200
// 0211200
// 0222200
// 0000000