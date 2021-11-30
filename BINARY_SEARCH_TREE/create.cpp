#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};
node* insert_BST(node*root,int d){
    if(root==nullptr)
    return new node(d);
    if(d<=root->data)
     root->left=insert_BST(root->left,d);
     else
     root->right=insert_BST(root->right,d);
     //cout<<"root data"<<root->data<<endl;
     return root;

}
node*build(){
    int d;
    //cout<<"enter root data"<<endl;
    cin>>d;
    node*root=nullptr;
    while(d!=-1){
        root=insert_BST(root,d);
        cin>>d;
    }
    return root;
}
void level_order_BFS(node*root){
queue<node*>q;
if(root){
q.push(root);
q.push(nullptr);
}
while(!q.empty()){
    node* p=q.front();
    
    cout<<q.front()->data<<" ";
     q.pop();
    if(p->left)
    q.push(p->left);
    if(p->right)
    q.push(p->right);
    
}
}
node*search(node*root,int data){
    if(root==nullptr)
    return nullptr;
    if(root->data==data)
    return root;
    else if(data<root->data)
    return search(root->left,data);
    else
    return search(root->right,data);
}

node* delete_BST(node*root,int key){
  if(root==nullptr)
  return nullptr;
  if(key<root->data)
   {root->left= delete_BST(root->left,key);
   return root; }
   else if(key==root->data){
       //1.no child
       if(root->left==nullptr and root->right==nullptr)
        {
        delete root;
        return nullptr;
        }
        //2. 1 child
        if(root->left && root->right==nullptr){
            node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->right && root->left==nullptr)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left and root->right){
            node* rep=root->right;
            while(rep->left!=nullptr)
             rep=rep->left;
            root->data=rep->data;
            root->right=delete_BST(root->right,rep->data);
            return root;
        }
   }
   else{
       root->right=delete_BST(root->right,key);
       return root;
   }
   return root;
}
bool is_BST(node*root,int min=INT_MIN,int max=INT_MAX){
    if(root==nullptr)
    return true;
    if(root->data>min and root->data<max and is_BST(root->left,min,root->data)and is_BST(root->right,root->data,max)){
        return true;
    }
    return false;
}
node* build_from_preorder(int*pre,int*in,int s,int e){
    static int i=0;
    if(s>e)
    return nullptr;
    int index=-1;
    node*root=new node(pre[i]);
    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left=build_from_preorder(pre,in,s,index-1);
    root->right=build_from_preorder(pre,in,index+1,e);
    return root;

}
//2  252  401 398  330 344 397 363
//924 220 911 244 898 258 362 363
//925 202 911 240 912 245 363
//2 399 387 219 266 382 381 278 363
int main(){
    node*root=build();
    level_order_BFS(root);
    //node*del= delete_BST(root,12);
    //level_order_BFS(del);
    //node*d=search(root,8);
    //cout<<d->data;
    /*if(is_BST(root)){
        cout<<"yes";
    }
    else{
        cout<<"NO";
    }
    int pre[7]={};*/
    return 0;
}