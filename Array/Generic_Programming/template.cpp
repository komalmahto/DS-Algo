#include <iostream>
#include <list>
using namespace std;
template<class ForwardIterator,class T,class compare>
ForwardIterator search(ForwardIterator start,ForwardIterator end,T b,compare cmp){
    while(start!=end){
        if(cmp(*start,b)){
            return start;
        }
        start++;
    }
    return end;
}
class book{
    public:
    string book_name;
    int price;
    book(string book_name,int price){
        this->book_name=book_name;
        this->price=price;
    }
};
class compare{
    public:
    bool operator()(book A,book B){
        if(A.book_name==B.book_name){
          return true;
        }
        return false;
    }
};

int main(){
 /*list<int>l;
 l.push_back(1);
 l.push_back(2);
 l.push_back(3);
 l.push_back(4);
 l.push_back(5);*/
 book b1{"phy",100};
 book b2{"chem",120};
 book b3{"math",160};
 book b4{"comp",100};
 list<book>l;
 l.push_back(b1);
 l.push_back(b2);
 l.push_back(b3);
 l.push_back(b4);
 compare cmp;
 /*if(cmp(b1,b1)){
     cout<<"good";
 }
 else{
     cout<<"not compatible";
 }*/
 auto it=search(l.begin(),l.end(),b3,cmp);
 if(it!=l.end()){
     cout<<"FOUND ";
 }
 return 0;
}