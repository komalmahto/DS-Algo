#include <iostream>
#include <cstring>
using namespace std;
class x{
    int y;
    public:
    x(short ss){
        cout<<"short"<<endl;
    }
    x(int xx){
        cout<<"Int"<<endl;
    }
    x(char ch){
        cout<<"Char"<<endl;
    }
    ~x(){
        cout<<"final"<<endl;
    }
};
int main(){
    x *p=new x('8');
    return 0;

}