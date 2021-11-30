#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
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
        v[i.first]=INT_MAX;
    }
    q.push(root);
    v[root]=0;
    while(!q.empty()){
      T f=q.front();
      cout<<f<<" ";
      q.pop();
      for(auto i:m[f]){
          if(v[i]==INT_MAX)
          {
          q.push(i);
          v[i]=v[f]+1;
          }
      }
    }
    cout<<endl;
     for(auto i:m){
      T node=i.first;
      T d= v[node];
      cout<<"NODE "<<node<<" dis "<<d<<endl;
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
    g.bfs(0);
    cout<<endl;
    //g.print_nbr();
    //g.print_dis();
    return 0;
}
/*
0 1 3 2 4 5 
NODE 0 dis 0
NODE 1 dis 1
NODE 2 dis 2
NODE 3 dis 1
NODE 4 dis 2
NODE 5 dis 3
*/