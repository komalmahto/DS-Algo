#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>

class BFS{
map<T,list<T>>m;
public:
void add_edge(T x,T y){
    m[x].push_back(y);
    m[y].push_back(x);
}
void bfs(T root){
    queue<T>q;
    map<T,T>v;
    for(auto i:m){
        T node=i.first;
        v[node]=0;
    }
    q.push(root);
    v[root]=1;
    while(!q.empty()){
      T f=q.front();
      cout<<f<<" ";
      q.pop();
      for(auto i:m[f]){
          if(!v[i])
          {
          q.push(i);
          v[i]=1;
          }
      }
    }
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
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(0,3);
    g.bfs(3);
    cout<<endl;
    g.print_nbr();
    return 0;
}
/*
3 2 4 0 1 5 
0 -> 1 3
1 -> 0 2
2 -> 1 3
3 -> 2 4 0
4 -> 3 5
5 -> 4
*/