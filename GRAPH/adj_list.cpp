#include<iostream>
#include<list>
using namespace std;
/*
0->1,2
1->0,2
2->0,1,3
3->2
*/
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
  void print_graph(){
     for(int i=0;i<v;i++){
         cout<<i<<" -> ";
         for(auto nbr:l[i]){
             cout<<nbr<<" ";
            }
            cout<<endl;
     }
  }

};
int main(){
  graph a(4);
  a.add_edge(0,1);
  a.add_edge(1,2);
  a.add_edge(2,3);
  a.add_edge(0,2);
  a.print_graph();
    return 0;
}
