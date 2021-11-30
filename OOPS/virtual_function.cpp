/*Virtual Function in C++
Difficulty Level : Medium
Last Updated : 29 Jan, 2021
A virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function. 

Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
They are mainly used to achieve Runtime polymorphism
Functions are declared with a virtual keyword in base class.
The resolving of function call is done at Run-time.
Rules for Virtual Functions

Virtual functions cannot be static.
A virtual function can be a friend function of another class.
Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
The prototype of virtual functions should be the same in the base as well as derived class.
They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
A class may have virtual destructor but it cannot have a virtual constructor.
*/
// CPP program to illustrate
// concept of Virtual Functions
 #include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Circle
{
    public:
    long long int center,radius,left,right;

    Circle(long long int c,long long int r)
    {
        center=c;
        radius=r;
        left=c-r;
        right=c+r;
        }
    };

bool compare(Circle a,Circle b)
{
    return a.center<b.center;
    }

int main()
{
    int n;
    cin>>n;
    vector<Circle> v;
    for(int i=0;i<n;i++)
    {
        int c,r;
        cin>>c>>r;
        Circle circle(c,r);
        v.push_back(circle);
        }
    
    //sorting on the basis of their center position
    sort(v.begin(),v.end(),compare);
    
    long long int right_most{0};
    right_most=v[0].right;
    long long int count{1};
    for(int i=1;i<n;i++)
    {
        Circle curr_circle=v[i];
        if(curr_circle.left<=right_most  )
        {
            count++;
            }
            else{
               right_most=curr_circle.right;
            }
        }
    
    cout<<count;
    return 0;
    }
#include <iostream>
using namespace std;
 
class base {
public:
    virtual void print ()
    {
        cout << "print base class" << endl;
    }
 
    void show()
    {
        cout << "show base class" << endl;
    }
};
 
class derived : public base {
public:
    void print()
    {
        cout << "print derived class" << endl;
    }
 
    void show()
    {
        cout << "show derived class" << endl;
    }
};
 
int main()
{
    base* bptr;
    derived d;
    bptr = &d;
 
    // virtual function, binded at runtime
    bptr->print();
 
    // Non-virtual function, binded at compile time
    bptr->show();
}
// Output:  
// print derived class
// show base class
/*
Explanation: Runtime polymorphism is achieved only through a pointer (or reference) of base class type. Also, a base class pointer can point to the objects of base class as well as to the objects of derived class. In above code, base class pointer ‘bptr’ contains the address of object ‘d’ of derived class.
Late binding(Runtime) is done in accordance with the content of pointer (i.e. location pointed to by pointer) and Early binding(Compile time) is done according to the type of pointer, since print() function is declared with virtual keyword so it will be bound at run-time (output is print derived class as pointer is pointing to object of derived class ) and show() is non-virtual so it will be bound during compile time(output is show base class as pointer is of base type ).
NOTE: If we have created a virtual function in the base class and it is being overridden in the derived class then we don’t need virtual keyword in the derived class, functions are automatically considered as virtual functions in the derived class.*/