#include<iostream>
#include <unordered_map>
#include<list>
using namespace std;
class graph{
   unordered_map<string,list<pair<string,int>>>l;
   public:
   void add_edge(string x,string y,int wt,bool flag){
    l[x].push_back(make_pair(y,wt));
    if(flag){
     l[y].push_back(make_pair(x,wt));
    }
   }
   void print_edge(){
       for(auto i:l){
           cout<<i.first<<" -> ";
           list<pair<string,int>>it=i.second;
           for(auto j: it){
               cout<<j.first<<" "<<j.second<<" , ";
           }
           cout<<endl;
       }
   }
};
int main(){
    graph g;
    g.add_edge("A","B",20,true);
    g.add_edge("B","D",30,true);
    g.add_edge("D","C",40,true);
    g.add_edge("C","A",10,true);
    g.add_edge("A","D",50,false);
    g.print_edge();
    return 0;
}
/*
C -> D 40 , A 10 , 
D -> B 30 , C 40 ,
A -> B 20 , C 10 , D 50 ,
B -> A 20 , D 30 ,
*/