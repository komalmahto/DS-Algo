#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;
template<typename T>
class BFS{
    map<T,list<T>>m;
    public:
    void add_edge(T x,T y){
        m[x].push_back(y);
        //m[y].push_back(x);
}
    
    void bdf_srt_dis(T src,T dst){
        queue<T>q;
        map<T,T>v;
        map<T,T>parent;
        for(auto i:m){
            v[i.first]=INT_MAX;
        }
        v[src]=0;
        parent[src]=src;
        q.push(src);
        while(!q.empty()){
            T f=q.front();
            //cout<<f<<" ";
            q.pop();
            for(auto i: m[f]){
                if(v[i]==INT_MAX){
                    q.push(i);
                    v[i]=v[f]+1;
                    parent[i]=f;
                }
            }
        }
        /*cout<<endl;
        for(auto i:m){
             int node=i.first;
             int dis=v[node];
             cout<<"NODE "<<node<<" dis "<<dis<<endl;
        }*/
        T temp=dst;
        while(temp!=src){
            cout<<temp<<" <---- ";
             temp=parent[temp];
        }
        cout<<src;
        //cout<<v[dst];
    }
    void print_nbr(){
    for(auto i:m){
        cout<<i.first<<" -> ";
        list<T>nbr=i.second;
        for(auto j:nbr){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
};
int main(){
    BFS<int>g;
    /*g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(0,3);
    g.bdf_srt_dis(0);
    cout<<endl;
    //g.print_nbr();
    //g.print_dis();*/
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
           int k=i+dice;
           k+=board[k];
           if(k<=36){
               g.add_edge(i,k);
           }
        }
    }
    g.add_edge(36,36);
    
    g.bdf_srt_dis(0,36);
    cout<<endl;
   g.print_nbr();
    return 0;
}
/*
36 <---- 30 <---- 29 <---- 15 <---- 0
0 -> 1 15 3 4 7 6
1 -> 15 3 4 7 6 7
2 -> 3 4 7 6 7 8
3 -> 4 7 6 7 8 27
4 -> 7 6 7 8 27 10
5 -> 6 7 8 27 10 11
6 -> 7 8 27 10 11 12
7 -> 8 27 10 11 12 13
8 -> 27 10 11 12 13 14
9 -> 10 11 12 13 14 15
10 -> 11 12 13 14 15 16
11 -> 12 13 14 15 16 4 
12 -> 13 14 15 16 4 29
13 -> 14 15 16 4 29 19
14 -> 15 16 4 29 19 6
15 -> 16 4 29 19 6 21
16 -> 4 29 19 6 21 22
17 -> 29 19 6 21 22 23
18 -> 19 6 21 22 23 16
19 -> 6 21 22 23 16 35
20 -> 21 22 23 16 35 26
21 -> 22 23 16 35 26 27
22 -> 23 16 35 26 27 28 
23 -> 16 35 26 27 28 29
24 -> 35 26 27 28 29 30
25 -> 26 27 28 29 30 31
26 -> 27 28 29 30 31 30
27 -> 28 29 30 31 30 33
28 -> 29 30 31 30 33 12
29 -> 30 31 30 33 12 35
30 -> 31 30 33 12 35 36
31 -> 30 33 12 35 36
32 -> 33 12 35 36
33 -> 12 35 36 
34 -> 35 36
35 -> 36
36 -> 36
*/