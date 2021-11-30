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
        m[y].push_back(x);
    }
    void helper(T src,map<T,bool>&visited){
        cout<<src<<" ";
        visited[src]=true;
        for(auto i: m[src]){
            if(!visited[i]){
                //visited[i]=true;
                helper(i,visited);
            }
        }
    }

    void DFS(T src){
        map<T,bool>visited;
        for(auto i:m){
            T node=i.first;
            visited[node]=false;
        }
        int ct=0;
        for(auto p:m){
         T node=p.first;
         if(!visited[node]){
          cout<<"Component "<< ct <<" ---> ";
           helper(node,visited);
           ct++;
         }  
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
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,1);
    //g.add_edge(4,5);
    g.add_edge(0,3);
    g.add_edge(5,6);
    // g.add_edge(8,9);
    // g.add_edge(10,11);
    // g.add_edge(11,12);

    g.DFS(0);
    //g.print_nbr();
    cout<<endl;
    return 0;
}
/*
Component 0 ---> 0 1 2 3 4 5 Component 1 ---> 7 8 9 Component 2 ---> 10 11 12 
*/

#include<iostream>
#include<climits>
#include<list>
#include<map>
#include<unordered_map>
#include<set>
#include<bits/stdc++.h>
using namespace std;
class graph{
	unordered_map<int,list<int>>m;
	public:
	void add_edge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}
     int ans=0;
	int dijkstra(int src,int a,int b,map<int,bool>&visited){
		map<int,int>dist;
		//memset(visited,0,n);
		for(auto i:m){
           int node=i.first;
		   dist[node]=INT_MAX;
		}

       dist[src]=0;
	   visited[src]=true;
	   set<pair<int,int>>s;
	    ans+=a;
	   s.insert(make_pair(a,src));
	   while(!s.empty()){
	   auto p=*(s.begin());
       int node=p.second;//1
       int nodeDist=p.first;//2
	   
       s.erase(p);
	   for(auto i:m[node]){
		   int childnode=i;//2
		   int childdist=min(a,b);
		   int max_=max(a,b);
		   if(nodeDist+childdist<=max_){
			   ans+=childdist;
			   visited[childnode]=true;
			   auto f=s.find(make_pair(dist[childnode],childnode));
             if(f!=s.end()){
                 s.erase(f);
             }
			   dist[childnode]=childdist+nodedist;
			   s.insert(make_pair(dist[childnode],childnode));
		   }
		   else{
                 dist[childnode]=nodedist+childdist;
                 ans+=childdist;
                 visited[childnode]=false;
                 return childnode;
           }
	   }
	   }
	return ans;
	}
	void dijkstra_helper(int n,int a,int b){
     map<int,bool>visited;
	 for(auto i:m){
		 int node=i.first;
		 visited[node]=false;
	 }
	
	 int ans=0;
		for(auto i:m){
           int node=i.first;
		   if(!visited[node])
		   node =dijkstra(node,a,b,visited);
		}
        // for(auto i:visited){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
		cout<<ans;
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	graph g;
	while(m--){
        int x,y;
		cin>>x>>y;
		g.add_edge(x,y);
	}

	g.dijkstra_helper(n,a,b);
	cout<<endl;
	}
	return 0;
}

#include<iostream>
#include<climits>
#include<list>
#include<map>
#include<unordered_map>
#include<set>
#include<bits/stdc++.h>
using namespace std;
map<int,int>dist;int ans=0;
class graph{
	unordered_map<int,list<int>>m;
	public:
	void add_edge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}
     
	int dijkstra(int src,int a,int b,map<int,bool>&visited){
		
		//memset(visited,0,n);
		

       dist[src]=0;
	   visited[src]=true;
	   set<pair<int,int>>s;
	    ans+=a;
	   s.insert(make_pair(0,src));
	   while(!s.empty()){
	   auto p=*(s.begin());
       int node=p.second;//1
       int nodeDist=p.first;//0
	   
       s.erase(p);
	   for(auto i:m[node]){
		   int childnode=i;//2
		   int childdist=min(a,b);
		   int max_=max(a,b);
		   if(nodeDist+childdist<=max_ and nodeDist+childdist<dist[childnode]){
			   ans+=childdist;
			   visited[childnode]=true;
			   auto f=s.find(make_pair(dist[childnode],childnode));
             if(f!=s.end()){
                 s.erase(f);
             }
			   dist[childnode]=dist[node]+childdist;
			   s.insert(make_pair(dist[childnode],childnode));
		   }
		   else{ if(!visited[childnode]){
                 dist[childnode]=dist[node]+childdist;
                 ans+=childdist;
                 visited[childnode]=false;
                 return childnode;
           }
           }
	   }
	   }
    //    for(auto i:dist){
    //        cout<<i.first<<" "<<i.second<<endl;
    //    }
	return ans;
	}
	void dijkstra_helper(int n,int a,int b){
     map<int,bool>visited;
     for(auto i:m){
           int node=i.first;
		   dist[node]=INT_MAX;
		}
	 for(auto i:m){
		 int node=i.first;
		 visited[node]=false;
	 }
	
		for(auto i:m){
           int node=i.first;
		   if(!visited[node])
		   node =dijkstra(node,a,b,visited);
		}
        // for(auto i:visited){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
		cout<<ans;
        ans=0;
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	graph g;
	while(m--){
        int x,y;
		cin>>x>>y;
		g.add_edge(x,y);
	}

	g.dijkstra_helper(n,a,b);
	cout<<endl;
	}
	return 0;
}

