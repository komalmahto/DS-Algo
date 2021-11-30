#include <iostream>
#include <cstring>
using namespace std;
class x{
    int val;
    public:
    void set(char* str1,char* str2){
        val=strcspn(str1,str2);

    }
    void show(){
        cout<<val;
    }
};
int main(){
    x obj;
    obj.set((char*)"India",(char*)"Bix");
    obj.show();
    return 0;
}
