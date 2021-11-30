#include<iostream>
#include<queue>
using namespace std;
class node{
    
    public:
    node*right;
    node*left;
    int data;
  node(int d){
     data=d;
     left=nullptr;
     right=nullptr;
  }
  
};
//BUILD BINARY TREE
node* build_binary_tree(){
      int d;
      cin>>d;
      if(d==-1)
      return nullptr;
      node* root=new node(d);
      cout<<"left of "<<d<<"->";
      root->left=build_binary_tree();
      cout<<"right of "<<d<<"->";
      root->right=build_binary_tree();
      return root;

  }
  //PREORDER TRAVERSAL
  void print_tree_preorder(node*root){
      if(root==nullptr)
      return ;
      cout<<root->data;
      print_tree_preorder(root->left);
      print_tree_preorder(root->right);

  }

//INORDER TRAVERSAL
void print_tree_inorder(node* root){
    if(root==nullptr)
    return;
    print_tree_inorder(root->left);
    cout<<root->data;
    print_tree_inorder(root->right);

}

//POSTORDER TRAVERSAL
void print_tree_postorder(node*root){
    if(root==nullptr)
    return;
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    cout<<root->data;
    
}

//HEIGHT OF A BINARY TREE
int height_binary_tree(node*root){
    if(root==nullptr)
    return 0;
    int x=height_binary_tree(root->left);
    int y=height_binary_tree(root->right);
    return x>=y?x+1:y+1;
}

//LEVEL ORDER TRAVERSAL RECURSION
void level_order(node*root,int k){
if(root==nullptr)
return ;
if(k==1)
{cout<<root->data;
return;}

level_order(root->left,k-1);
level_order(root->right,k-1);
return;
}
void driver(node*root){
    int h=height_binary_tree(root);
    for(int i=1;i<=h;i++){
        level_order(root,i);
        cout<<endl;
    }
}

//LEVEL ORDER BFS(QUEUE)
void level_order_BFS(node*root){
queue<node*>q;
if(root){
q.push(root);
q.push(nullptr);
}
while(!q.empty()){
    node* p=q.front();
    if(p==nullptr){
    cout<<endl;
    q.pop();
    if(!q.empty()){
        q.push(nullptr);
    }
    }else{
    cout<<q.front()->data;
     q.pop();
    if(p->left)
    q.push(p->left);
    if(p->right)
    q.push(p->right);
    }
}
}

int replace_with_sum_greater_nodes(node*root){
    static int sum=0;
    if(!root){
    return 0;
    }
    //if(!root->left)
    int x=replace_with_sum_greater_nodes(root->right);
    int temp=root->data;
    root->data=sum;
    sum+=temp;
    int y=replace_with_sum_greater_nodes(root->left);
    return sum;
    
}

int main(){
    node*root=  build_binary_tree();
    print_tree_postorder(root);
    //driver(root);
    //cout<<height_binary_tree(root);
    //print_tree_postorder(root);
    return 0;
}