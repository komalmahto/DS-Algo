#include <iostream>
using namespace std;
class base{
    int x,y,z;
    public:
    base(){
        x=y=z=0;
    }
    base(int xx,int yy='A',int zz='B'){
        x=xx;
        y=x+yy;
        z=x+y;
    }
    void display(void){
     cout<<x<<" "<<y<<" "<<z<<endl;
    }
};
class der:public base{
    int x,y;
    public:
    der(int xx=65,int yy=66)
     :base(xx,yy){
       y=xx;
       x=yy;
    }
    void diaplay(void){
        cout<<x<<" "<<y<<" "<<endl;
        display();
    }
};
int main(){
der obj;
obj.display();
}
