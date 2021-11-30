/*
Finding cycle in undirected graph
Non overlapping
two operations- union and find
S1 -> 1,2,3,4
S2 -> 5,6,7
S3 -> 8,9
Find(8) -> S3
Finf(6) -> S2
union -> merge two sets into one.
union(s3,s2) or union(6,8)  in this case s2 and s3 
will be gone and new set would be created
Find and union take o(n) time we will reduce it to o(1) time
by 
1. Path Compression
2. Union by rank
*/
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class graph{
    list<pair<int,int>>l;
    int v;
    public:
    graph(int v){
        this->v=v;
    }
    void add_edge(int x,int y){
        l.push_back(make_pair(x,y));
    }
    int find_set(int i,int parent[]){
        if(parent[i]==-1)
        return i;
      return parent[i]=find_set(parent[i],parent);
}
    void union_set(int x,int y,int parent[],int rank[]){
       int s1=find_set(x,parent);
       int s2=find_set(y,parent);
       if(s1!=s2){
           if(rank[s1]<rank[s2]){
               parent[s1]=s2;
               rank[s2]+=rank[s1];
           }else{
               parent[s2]=s1;
               rank[s1]+=rank[s2];
           }
           
       }
    }
    bool contain_cycle(){
        int *parent=new int[v];
        int *rank=new int[v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        for(auto i:l){
            int f=i.first;
            int g=i.second;
            int s1=find_set(f,parent);
            int s2=find_set(g,parent);
            if(s1!=s2){
                union_set(s1,s2,parent,rank);
            }
            else{
                cout<<"contain_cycle ";
                return true;
            }
        }
        /*int ans=0;
        for(int i=0;i<v;i++){
            ans+=v-rank[find_set(i,parent)];
        }*/
        return false;
    }
    
};
int main(){
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,0);
    cout<<g.contain_cycle();
    return 0;
}
// contain_cycle 1
