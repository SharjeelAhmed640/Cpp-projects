#include <iostream>
#include <cstring>
#include <cmath>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{

    ifstream f("TASK6.txt", ios::ate);
    f.seekg(0);
    char c;
    int count = 0;
    bool check = true;
    f.get(c);
    while (!f.eof())
    {
        f.get(c);
        if ((c == 'A' || c == 'a') && check == true)
        {
            count++;
            check = false;
        }
        else if (c == 13 || c == '\n')
        {
            check = true;
        }
    }
    cout <<endl<< "count : " << count << endl;
}