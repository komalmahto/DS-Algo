#include <bits/stdc++.h>
using namespace std;
class heap{
    vector<int>h;
    bool heap_type;
    private:
    bool compare(int c,int p)
    {
        if(heap_type==true){
            return c < p;
        }else{
            return c >  p;
        }
    }
    void heapify(int idx){
     int left=2*idx;
     int right=left+1;
     int min_idx=idx;
     int last=h.size()-1;
     if(left<=last and compare(h[left],h[idx])){
         min_idx=left;
     }
     if(right<=last and compare(h[right],h[min_idx])){
       min_idx=right;
         }
       if(min_idx!=idx){
           swap(h[min_idx],h[idx]);
            heapify(min_idx);  
       }  
      
    }
      
    public:
    heap(int n=10,bool flag=true){
        h.reserve(n);
        h.push_back(-1);
        heap_type=flag;//if flag is true min heap
        }
        void push(int data){
         h.push_back(data); 
         int child=h.size()-1;
         int parent=child/2;
         while(child>1 and compare(h[child],h[parent])){
              swap(h[child],h[parent]);
              child=parent;
              parent=parent/2;

         }
        }
       int get(){
           return h[1];
       }
       void pop(){
           swap(h[1],h[h.size()-1]);
           h.pop_back();
           heapify(1);
       }
       bool empty(){
           return h.size()==1;
       }
       void merge(){
           int x,y,sum,s;
           while(h.size()!=2)
           {
               if(get())
                { x=get();
                   pop();
                }
               if(get())
                { y=get();
                   pop();
                }
           sum=x+y;
           push(sum);
           s+=sum;
           cout<<s<<" ";
           }cout<<endl;
           cout<<s;
       }
};
int main(){
    heap p(7,true); int n;
    for(int i=0;i<7;i++){
      cin>>n;
      p.push(n);
    }
    p.merge();
}