#include <iostream>
#include <cstring>
#include <cmath>
enum BOOL 
{   TRUE=1,FALSE=0};
class CGPA{
    int thesis_cgpa,thesis_creditHrs;
    public:
    CGPA(int cgpa=0,int hrs=0)
    {
        this->thesis_cgpa=cgpa;
        this->thesis_creditHrs=hrs;
    }
    BOOL CheckEligiblity()
    {
        if(this->thesis_cgpa>=3 && this->thesis_creditHrs>=26)
        return TRUE;

        else
        return FALSE;
    }
};
using namespace std;
int main()
{
int cgpa,HRS;
cout<<"Enter credit hours : ";
//cin.ignore();
cin>>HRS;
cout<<"Enter CGPA : ";
//cin.ignore();
cin>>cgpa;
CGPA sharjeel(cgpa,HRS);
int eligiblity=sharjeel.CheckEligiblity();
if(eligiblity==TRUE)
cout<<"\nYou are eligible Thesis."<<endl;

else
cout<<"\nYou are not eligible Thesis."<<endl;


return 0;
}