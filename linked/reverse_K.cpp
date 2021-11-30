#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 

//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
	list <int> :: iterator it; 
	for(it = g.begin(); it != g.end(); ++it) 
		cout << '\t' << *it; 
	cout << '\n'; 
} 
void reverse(list <int> g,list <int>p){
	if(p!=0){
		reverse(p,p->next);
		p->next=nullptr;
	}else{
		
	}
}
int main() 
{ 
   int n=9,k=0;
   //cin>>n>>k;
	list <int> gqlist1; 
    for (int i = 0; i < 9; ++i) 
	{ 
		gqlist1.push_back(i+1); 
		//gqlist2.push_front(i * 3); 
	}
	
	cout << "\nList 1 (gqlist1) is : "; 
	showlist(gqlist1); 
    return 0; 

} 
