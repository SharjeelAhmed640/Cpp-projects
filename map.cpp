#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map < string , int > marksmap ;
    
    marksmap["sharjeel"] = 99 ;
    marksmap.insert ({{"Ahmed"s,99},{"Kanza"s,100}});
    map<string, int>::iterator iter;
    for (iter = marksmap.begin(); iter != marksmap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }

    return 0;
}