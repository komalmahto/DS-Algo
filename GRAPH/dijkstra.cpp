#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;
template<typename T>

class dijkstra{
    unordered_map<T,list<pair<T,int>>>H;
    public:
    void addEdge(int x,int y,int wt,bool fg=true){
        H[x].push_back(make_pair(y,wt));
        if(fg){
            H[y].push_back(make_pair(x,wt));
        }
    }
    void printDij(){
        for(auto i:H){
         cout<<i.first<<": ";
          for(auto j:i.second){
              cout<<j.first<<" "<<j.second<<" , ";
          }
          cout<<endl;
          }
    }
    void Dijskstra(int src){
        unordered_map<T,int>dist;
        for(auto j:H){
         dist[j.first]=INT_MAX;
        }
        set<pair<int,T>>s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p = *(s.begin());
           cout<<p.first<<" "<<p.second;//0 1
           int dist=p.first;
           T node=p.second;
           s.erase(s.begin());
           for(auto nbr:H[node]){
               T city=nbr.first;//city
               int city_dis=nbr.second;//weight
               if(dist + city_dis < dist[nbr.first]){
               dist[nbr.first]= dist + city_dist;
               }
           }
             //cout<<p;
             /*T nm=p.second;
            int node_dis= p.first;
            s.erase(s.begin());
            for(auto nbr:H[nm]){
                if(node_dis + nbr.second < dist[nbr.first]){
                    nbr.first=node_dis+nbr.second;
                }
            }
        }*/
        s.erase(s.begin());
      }

}
};
int main(){
    dijkstra<int>dj;
    dj.addEdge(1,2,1);
    dj.addEdge(1,3,4);
    dj.addEdge(2,3,1);
    dj.addEdge(3,4,2);
    dj.addEdge(1,4,7);
    dj.printDij();
    dj.Dijskstra(1);
    return 0;
}
