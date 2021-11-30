//Jiski indegree 0 h use queue m insert karo
//and jabtak vo empty na ho run karo .
//pop kro 
//and uske neighbours k indegree ko 1 reduce kro 
//and jab neighbour k indegree 0 ho jae to queue m 
//push kaaro and repeat the process.

#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class graph{
    list<int>*l;
    int v;
    public:
    graph(int v){
        this->v=v;
     l=new list<int>[v];
    }
    void add_edge(int x,int y){
        l[x].push_back(y);
    }
    void topological_sort(){
        int *indegree=new int[v];
        for(int i=0;i<v;i++){
            indegree[i]=0;
        }
        for(int i=0;i<v;i++){
            for(auto y:l[i]){
                indegree[y]++;
            }
        }
        for(int i=0;i<v;i++){
            cout<<i<<" --> "<< indegree[i]<<endl;
        }

        //bfs
        queue<int>q;
        for(int i=0;i<v;i++){
          if(indegree[i]==0)
          q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            cout<<node<<" --> ";
            q.pop();
            for(auto nbr:l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                q.push(nbr);
            }
        }
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
    graph g(6);
    g.add_edge(0,2);
    g.add_edge(1,4);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(2,5);
    g.add_edge(3,5);
    g.add_edge(4,5);
    g.topological_sort();
    cout<<endl;
    g.print_graph();
    return 0;
}
/*
0 --> 0
1 --> 0
2 --> 2
3 --> 1
4 --> 1
5 --> 3
0 --> 1 --> 4 --> 2 --> 3 --> 5 -->
0 -> 2
1 -> 4 2
2 -> 3 5
3 -> 5
4 -> 5
5 ->*/