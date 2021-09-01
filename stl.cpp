#include <iostream>
#include <vector>
using namespace std;
template <class T>

void display ( vector<T>  &v )
{
    cout<<"Displaying this vector of length : "<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout  << v.at(i)<< "\t";
    }
    cout<<endl;
}
int main()
{
    // vector<int> v1;
    // display(v1);
    
    // vector<char> v2(4);
    // v2.push_back('5');
    // display(v2);

    // vector <int> v3 ( v2 );

    vector<int> v4(3,3);
    display(v4);
    v4.front();
    

    
    // int element, size;
   
   
   
   
    // cout << "Enter the size : ";
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter an element to add to this vector : ";
    //     cin >> element;
    //     v1.push_back(element);
    //     //cin>>v1[i];
    // }
    
    // display(v1);
    // vector<int> :: iterator iter = v1.begin();
    // v1.insert(iter,556);
    // display(v1);

    return 0;
}
