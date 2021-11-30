// level order gives shortest path


#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
map<T,list<int>>l;
public:
    void addEdge(int x,int y){
    l[x].push_back(y);
    l[y].push_back(x);
    }
    void bfs(int src){
        map<T,int>dist;
        
// dist[src]=0; removed
    for(auto nbs:l){
        int x=nbs.first;
        dist[x]=INT_MAX;
        }
        dist[src]=0;// added here
        queue<T>q;
        q.push(src);
        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(auto d:l[node]){
                if(dist[d]==INT_MAX){// here u were usinf node
                    q.push(d);
                    dist[d]=dist[node]+1;
                    //children=parent+1;
                }
            }
        }
        for(auto node_dis: l){
            T node=node_dis.first;
            int dis=dist[node];
            cout<<"Node "<<node<<" distance from src "<<dis<<endl;
        }

    }

};
int main()
{ graph<int>g;
g.addEdge(0,1);
g.addEdge(0,3);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,5);

g.bfs(0);
}
