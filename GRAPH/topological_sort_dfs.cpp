#include<iostream>
#include<map>
#include<list>
using namespace std;
template <typename T>
class dfs{
    map<T,list<T>>m;
    public:
    void add_edge(T x,T y){
        m[x].push_back(y);
        //m[y].push_back(x);
    }
    void helper(T src,map<T,bool>&visited,list<T>&ordering){
        //cout<<src<<" ";
        visited[src]=true;
        for(auto i: m[src]){
            if(!visited[i]){
                //visited[i]=true;
                helper(i,visited,ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    void DFS(){
        map<T,bool>visited;
        list<T>ordering;
        for(auto i:m){
            T node=i.first;
            visited[node]=false;
        }
       
        for(auto p:m){
         T node=p.first;
         if(!visited[node]){
           helper(node,visited,ordering);
         }  
        }
        for(auto node:ordering){
            cout<<node<<"-->";
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
    dfs<int>g;
     g.add_edge(1,4);
     g.add_edge(1,3);
    g.add_edge(1,2);
     
     
       g.add_edge(2,3);
        g.add_edge(3,5);
         g.add_edge(4,5);
          g.add_edge(5,7);
           g.add_edge(6,7);


    // g.add_edge("python","data processing");
    // g.add_edge("python","pytorch");
    // g.add_edge("python","ML basics");
    // g.add_edge("pytorch","DL");
    // g.add_edge("ML basics","DL");
    // g.add_edge("DL","Face Recognititon");
    // g.add_edge("Data Set","Face Recognititon");
    g.print_nbr();
cout<<endl;
    /*g.add_edge(7,8);
    g.add_edge(8,9);
    g.add_edge(10,11);
    g.add_edge(11,12);*/

    g.DFS();
    //g.print_nbr();
    cout<<endl;
    return 0;
}
// DL -> Face Recognititon 
// Data Set -> Face Recognititon
// ML basics -> DL
// python -> data processing pytorch ML basics
// pytorch -> DL

// python-->pytorch-->data processing-->ML basics-->Data Set-->DL-->Face Recognititon-->




