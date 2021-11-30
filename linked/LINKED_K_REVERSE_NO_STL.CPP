#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node *head=new Node;

void R_Display(Node *ptr){
if(ptr){
 cout<<ptr->data<<" ";
 R_Display(ptr->next);
}
}
Node* mhead=nullptr;
Node* R_Reverse(Node* q,Node *p){
    if(p){
        R_Reverse(p,p->next);
        p->next=q;
    }
    else{
        mhead=q;
    }
 return mhead;   
}

int main()
{
   int A[]={3,4,5,6,7,0,1,4,5,6,7,8,9,0};int i,number,pos;Node *last,*temp;

head->data=A[0];
head->next=0;
last=head;
for(i=1;i<sizeof(A)/sizeof(A[0]);i++){
        temp=new Node;
    temp->data=A[i];
    temp->next=0;
    last->next=temp;
    last=temp;
} 
Node *p= head;
Node*q=nullptr;

R_Display(R_Reverse(q,p));
  return 0;
}
