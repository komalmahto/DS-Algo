#include<iostream>
#include<list>
#include<queue>
#include<climits>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;
template<typename T>
class graph{
    unordered_map<T,list<pair<T,int>>>m;
    public:
    void addEdge( T x,T y,int wt){
        m[x].push_back(make_pair(y,wt));
         m[y].push_back(make_pair(x,wt));
    }
    
void dijskstra(T src,T des){
 map<T,int>dist;
 set<pair<int,T>>s;
 map<T,T>parent;
 for(auto i:m){
      T node=i.first;
      dist[node]=INT_MAX;

 }   
 dist[src]=0;
 parent[src]=src;
 s.insert(make_pair(0,src));
 while(!s.empty()){
     auto p=*(s.begin());
     T node=p.second;
     int nodeDist=p.first;//0
     s.erase(p);
     for(auto child:m[node]){
         T childNode=child.first; //4
         int childDist=child.second;//7
         if(nodeDist+childDist<dist[childNode]){
             //cout<<childNode<<childDist<<endl;
             parent[childNode]=node;
             auto f=s.find(make_pair(dist[childNode],childNode));
             if(f!=s.end()){
                 s.erase(f);
             }
             dist[childNode]=nodeDist+childDist;
             s.insert(make_pair(dist[childNode],childNode));
            // cout<<dist[childNode]<<endl;//1
         }
     }
     
 }
 cout<<"Distance of source to all other node "<<endl;
 for(auto i:dist){
     cout<<i.first<<" ---> "<<i.second<<endl;
 }
 cout<<"Path from source to destination "<<endl;
 T temp=des;
 while(temp!=src){
     cout<<temp<<" <---- ";
     temp=parent[temp];
 }
 cout<<src;
}

void print_graph(){
    for(auto i:m){
        cout<<i.first<<" --> ";
        list<pair<T,int>>p=i.second;
        for(auto j:p){
            cout<<j.first<<" "<<j.second<<" , ";
        }
        cout<<endl;
    }
}
};
int main(){
    graph<int>dj;
    dj.addEdge(1,2,1);
    dj.addEdge(1,3,4);
    dj.addEdge(1,4,7);
    dj.addEdge(2,3,1);
    dj.addEdge(3,4,2);
    dj.dijskstra(1,3);
    cout<<endl;
    //dj.print_graph();

    return 0;
}
// Distance of source to all other node 
// 1 ---> 0
// 2 ---> 1
// 3 ---> 2
// 4 ---> 4
// Path from source to destination
// 3 <---- 2 <---- 1

