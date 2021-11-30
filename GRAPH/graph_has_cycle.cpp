//if graph has a back edge then it is a cycle
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
      //l[y].push_back(x);
  }
  bool has_cycle_helper(int node,bool *visited,bool *stack){
   visited[node]=true;
   stack[node]=true;
   for(auto nbr:l[node]){
       if(visited[nbr]==true and stack[nbr]==true){
           for(int i=nbr;i<=node;i++){
               cout<<i<<" --->> ";
          }
           cout<<endl;
           return true;
       }
       else if(!visited[nbr]){
        bool cycle_mila=has_cycle_helper(nbr,visited,stack);
        if(cycle_mila){
           return true; 
        }
       }
   }
   stack[node]=false;
   return false;
  }
  void has_cycle(){
      bool *visited=new bool[v];
      bool *stack=new bool[v];
      for(int i=0;i<v;i++){
          visited[i]=false;
      }
      
      cout<<has_cycle_helper(0,visited,stack);
      
  }
};
int main(){
graph a(8);
  a.add_edge(0,1);
  a.add_edge(1,2);
  a.add_edge(1,6);
  a.add_edge(1,5);
  a.add_edge(2,3);
  a.add_edge(3,4);
  a.add_edge(4,5);
  //a.add_edge(4,2);
  a.add_edge(5,1);
  //cout<<"Does This Graph Is A TREE ---> ";
  a.has_cycle();
  return 0;
}