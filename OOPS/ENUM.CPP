#include <iostream>
using namespace std;
enum xyz{
    a,b,c
};

int main()
{  
    int x=a,y=b,z=c;
    cout<<x<<y<<z<<endl;
    int &p=x,&q=y,&r=z;
    
    cout<<p<<q<<r<<endl;
    p=z;
    p=++q;
    q=++p;
    z=++q+p++;
    cout<<p<<" "<<q<<" "<<z;

    return 0;
}
