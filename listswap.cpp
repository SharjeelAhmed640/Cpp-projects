// swap lists
#include <iostream>
#include <list>
using namespace std;
int main ()
{
  list<int> first (3,100);   // three ints with a value of 100
  list<int> second (5,200);  // five ints with a value of 200

  first.swap(second);

  cout << "first contains:";
  for (list<int>::iterator it=first.begin(); it!=first.end(); it++)
    cout << ' ' << *it;
  cout << '\n';

  std::cout << "second contains:";
  for (list<int>::iterator it=second.begin(); it!=second.end(); it++)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}