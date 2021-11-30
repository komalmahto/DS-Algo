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
    //cout<<q.front()->data;
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
//cout<<endl;
map<int,vector<int>> ::iterator it1,it2;
int s=m.size();
for(auto i:m){
    //cout<<i.first<<" -> ";
	int c=0;
      for(int x:i.second){
          if(c==0)
		  cout<<x<<" ";
		  c++;
      }
     // cout<<endl;
}
}