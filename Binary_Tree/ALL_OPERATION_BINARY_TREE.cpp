#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    int hd;
    node(int d){
        data=d;
        right=nullptr;
        left=nullptr;
        hd=0;
    }
};
node*create_binary_tree(){
    int d;
    cin>>d;
    if(d==-1)
    return nullptr;
    node*root=new node(d);
    cout<<"left of "<<d<<"->";
    root->left=create_binary_tree();
     cout<<"right of "<<d<<"->";
    root->right=create_binary_tree();
    return root;
}
//DISPLAY
void display(node*root){
if(root==nullptr)
return;
cout<<root->data;
display(root->left);
display(root->right);
}

//COUNT NODES
int count_nodes(node*root){
    if(root==nullptr){
        return 0;
    }
    int x=count_nodes(root->left);
    int y=count_nodes(root->right);
    //cout<<x<<y<<endl;
    return x+y+1;
}

//SUM NODES
int sum_node(node*root){
    if(root==nullptr)
    return 0;
    int x=sum_node(root->left);
    int y=sum_node(root->right);
    return ((root->data)+x+y);
}

//HEIGHT NODES
int height(node*root){
    if(root==nullptr)
    return 0;
    int x=height(root->left);
    int y=height(root->right);
    return x>y?x+1:y+1;
}

//DIAMETER
int diameter(node*root){
    if(root==nullptr)
    return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}

//REPLACE NODES WITH SUM
int replace_node_sum(node*root){
    if(root==nullptr)
    return 0;
    if(root->left==nullptr && root->right==nullptr)
    return root->data;
    int x=replace_node_sum(root->left);
    int y=replace_node_sum(root->right);
    int temp=root->data;
    root->data=x+y;
    return (temp+x+y);
}

//CREATE BINARY TREE WITH ARRAY
node* create_binary_tree_array(int *a,int s,int e)
{
    if(s>=e)
    return nullptr;
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=create_binary_tree_array(a,s,mid-1);
    root->right=create_binary_tree_array(a,mid+1,e);
    return root;
}

//CREATE FROM PREORDER AND INORDER
node* create_from_preorder_inorder(int *pre,int *in,int s,int e)
{ 
    static int i=0;
    if(s>e)
    return nullptr;
    node*root=new node(pre[i]);
    int index=-1;
    for(int j=s;s<=e;j++){ 
        if(in[j]==pre[i])
         {
             index=j;
             break;
         }
    }
    i++;
   root->left=create_from_preorder_inorder(pre,in,s,index-1);
   root->right=create_from_preorder_inorder(pre,in,index+1,e);
   return root;
  
}

//RIGHT VIEW
void right_view(node*root,int level,int max_level){
    if(root==nullptr)
    return;
    if(max_level<level){
        cout<<root->data<<" ";
      max_level=level;
    }
    right_view(root->right,level+1,max_level);
    right_view(root->left,level+1,max_level);
    return ;
}

node*build_tree_levelorder(node*r,int d,queue<node*>q){
    node* root=new node(d);
    if(r==nullptr)
     r=root;
     else if(!q.front()->left){
         q.front()->left=root;
     }else{
         q.front()->right=root;
         q.pop();
     }
     q.push(root);
     return r;
}
void left_view(node*root,int level,int &max_level){
    
    if(!root)
    return ;
    if(max_level<level){
        cout<<root->data;
        max_level=level;
    }
    left_view(root->left,level+1,max_level);
    left_view(root->right,level+1,max_level);
    return ;
}
//LOWEST COMMON ANCESTOR
node*LCA(node*root,int a,int b){
    if(root==nullptr)
    return nullptr;
    if(root->data==a || root->data==b)
    return root;
    node*l=LCA(root->left,a,b);
    node*r=LCA(root->right,a,b);
    if(r and l)
    return root;
    if(l)
    return l;
    return r;

}

//DISTANCE BETWEEN NODES
int dis_between_nodes(node*root,int key,int level){
    if(root==nullptr)
    return 0;
    if(root->data==key)
    return level;
    int s=dis_between_nodes(root->left,key,level+1);
    if(s!=0)
    return s;
    int r=dis_between_nodes(root->right,key,level+1);
    return r;
}
int driver_dis_between_nodes(node*root,int a,int b){
    node* lca=LCA(root,a,b);
    int l1=dis_between_nodes(lca,a,0);
    int l2=dis_between_nodes(lca,b,0);
    return l1+l2;
}
int sum_at_level_k(node*root,int k){
    static int sum=0;
    if(!root)
    return 0;
    if(k==1){
        sum+=root->data;
        return sum;
    }
    sum_at_level_k(root->left,k-1);
    sum_at_level_k(root->right,k-1);
    return sum;
}
/*int print_at_distance_k(node*root,node*target,int dis)
{
	if(root==nullptr)
		return -1;
	
	if(root==target)
	{
		levelorder_print(target,dis+1);
		return 0;
		}
    
	int DL=print_at_distance_k(root->right,target,dis);
	
	if(DL!=-1)
	{
		if(DL+1==dis)
		{
			cout<<root->data<<" ";
			}
		else
		{
			levelorder_print(root->right,dis-DL-2);
			}
			
		return DL+1;
		}
	int DR=print_at_distance_k(root->left,target,dis);
	
	if(DR!=-1)
	{
		if(DR+1==dis)
		{
			cout<<root->data<<" ";
			}
		else
		{
			levelorder_print(root->left,dis-DR-2);
			}
		return DR+1;
		}
		return -1;
	}
*/
class hbpair{
    public:
    int height;
    bool is_balanced;
};
hbpair is_Balanced(node*root){
    hbpair hb;
    if(root==nullptr){
        hb.height=1;
        hb.is_balanced=true;
    }
    hbpair left=is_Balanced(root->left);
    hbpair right=is_Balanced(root->right);
    hb.height=max(left.height,right.height)+1;
    if(left.height-right.height<2 and left.is_balanced and right.is_balanced ){
       hb.is_balanced=true;
    }
    else{
        hb.is_balanced=false;
    }
    return hb;
}
void level_order_BFS(node*root){
queue<node*>q;
map<int,vector<int>>m;
if(root){
q.push(root);
root->hd=0;
m[root->hd].push_back(root->data);

}
while(!q.empty()){
    node* p=q.front();
    cout<<q.front()->data;
     q.pop();
    if(p->left)
    {q.push(p->left);
    p->left->hd=(p->hd)-1;
    m[p->left->hd].push_back(p->left->data);
    }
    if(p->right)
     {q.push(p->right);
     p->right->hd=(p->hd)+1;
     m[p->right->hd].push_back(p->right->data);
    }
}
cout<<endl;
map<int,vector<int>> ::iterator it1,it2;
int s=m.size();
for(auto i:m){
    cout<<i.first<<" -> ";
      for(int x:i.second){
          cout<<x;
      }
      cout<<endl;
}
}
int main(){
    node*root=create_binary_tree();
    level_order_BFS(root);
    //display(root);
    //right_view(root,0,-1);
    //cout<<count_nodes(root)<<endl;
    //cout<<sum_node(root);
    //cout<<diameter(root);
    //cout<<replace_node_sum(root);
    //display(root);
    //int max_level=-1
    //right_view(root,0,max_level);
    /*int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    node*r=create_from_preorder_inorder(pre,in,0,7);
    display(r);*/
    //cout<<sum_at_level_k(root,3);
    return 0;
}