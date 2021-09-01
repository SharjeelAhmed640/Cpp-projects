#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void a(int b=0)
{
  cout<<b;
}
void a(char b)
{
  cout<<b;
}
int main()
{
a(5);
a('b');
a();
return 0;
}