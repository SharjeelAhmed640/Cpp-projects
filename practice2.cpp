#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class base{
    public:
    void foo()
    {
        cout<<"hi";
    }
};
class derived:base{
    public:
    using base::foo;
    void foo(int)
    {
        cout<<"heyyy";
    }
};

int main()
{
    derived d1;
    d1.foo();
    d1.foo(1);
return 0;
}