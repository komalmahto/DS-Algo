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
bool has_cycle_helper(int node,bool *visited,int *parent){
    visited[node]=true;
    for(auto nbr:l[node]){
        if(visited[nbr]==false){
            parent[nbr]=node;
            //cout<<node<<" ";
        bool cycle_mila=has_cycle_helper(nbr,visited,parent);
        if(cycle_mila){
            return true;
        }
         
        }
        else if(parent[node]!=nbr)
        // {   int temp=node;
        //     cout<<temp<<nbr<<endl;
        //     while(temp!=nbr){
        //         cout<<temp<<" <---- ";
        //         temp=parent[temp];
        //     }
        //    cout<<nbr;
        //    cout<<endl;
        return true;
        }
    }
    return false;
}
bool has_cycle(){
    bool *visited=new bool[v];
    int *parent=new int[v];
    for(int i=0;i<=v;i++){
        visited[i]=false;
    }
    //bool *visited=new bool[v];
    return has_cycle_helper(0,visited,parent);

}

};
int main(){
graph a(4);
  /*a.add_edge(0,1);
  a.add_edge(1,2);
 //a.add_edge(1,5);
  a.add_edge(2,3);
  a.add_edge(3,4);
  a.add_edge(4,5);
  a.add_edge(4,2);
  a.add_edge(5,6);*/
  a.add_edge(0,1);
  a.add_edge(1,2);
  a.add_edge(2,3);
  a.add_edge(3,1);
  //cout<<"Does This Graph Is A TREE ---> ";
  cout<<a.has_cycle();
  return 0;
}
// 31
// 3 <---- 2 <---- 1
// 1