// if the node is visited more than 1 times ,is a graph else tree

#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

class graph{
    int v;
    list<int>*l;
    public:
  graph(int v){
      this->v=v;
      l=new list<int>[v];
  }
  void add_edge(int x,int y){
      l[x].push_back(y);
      l[y].push_back(x);
  }
  bool has_cycle(int src){
      map<int,bool>visited;
      map<int,int>parent;

      queue<int>q;
      q.push(src);
      visited[src]=true;
      parent[src]=src;
      while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto nbr:l[node]){
              if(visited[nbr]==true and parent[node]!=nbr)
              return false;
              else if(visited[nbr]!=true){
                  visited[nbr]=true;
                  parent[nbr]=node;
                  q.push(nbr);
              }
          }
      }
      return true;
  }
};
int main(){
graph a(4);
  a.add_edge(0,1);
  a.add_edge(1,2);
  a.add_edge(2,3);
  //a.add_edge(0,2);
  cout<<"Does This Graph Is A TREE ---> ";
  cout<<a.has_cycle(0);
  return 0;
}
// Does This Graph Is A TREE ---> 1