//filename: arrayaddder.cpp
//Modify this program to overload subtraction operator and insertion operator
#include <iostream>
using namespace std;

#define MAXARRAY 5

class myarray 
{
private:
	int value[MAXARRAY];

public:
	void setvalue(int index, int newvalue){
		value[index]=newvalue;}
	int getvalue(int index){
		return value[index];}
	myarray operator+(myarray array2)
	{
		myarray temparray;
		for (int i=0; i<MAXARRAY; i++)
			temparray.value[i]=value[i] + array2.value[i];
		return temparray;
	}
    myarray operator-(myarray b)
    {
        myarray temp;
        for(int i=0;i<MAXARRAY;i++)
        temp.value[i]=this->value[i]-b.value[i];
        return temp;
    }
friend ostream& operator <<(ostream& os,const myarray b);
//friend myarray operator-(myarray array1, myarray array2);
};
     ostream& operator <<(ostream& os,const myarray b) { 
         os <<"New array : ";
         for(int i=0;i<MAXARRAY;i++)
         os << b.value[i] << "\t"; 
         os<<endl;
         return os;        
      }
/*myarray operator-(myarray array1, myarray array2)
{
	myarray temparray;
	for (int i=0; i<MAXARRAY; i++)
		temparray.value[i]=array1.value[i] + array2.value[i];
	return temparray;
}
*/
int main ()
{

	myarray array1, array2, array3;
	int i;
	
	//INITIALIZE 
	for (i=0; i<MAXARRAY; i++)
	{
		array1.setvalue(i,i);
		array2.setvalue(i,i+3);
	}
	
	//ADD 
	array3=array1 + array2; 
	
	//PRINT 
	cout << "array1   array2   array3" << endl;
	for (i=0; i<MAXARRAY; i++)
		cout << array1.getvalue(i) << "        " 
		     << array2.getvalue(i) << "        " 
		     << array3.getvalue(i) << endl;

    //subtract 
	array3=array1 - array2; 
	
	//PRINT 
	cout << "array1   array2   array3" << endl;
	for (i=0; i<MAXARRAY; i++)
		cout << array1.getvalue(i) << "        " 
		     << array2.getvalue(i) << "        " 
		     << array3.getvalue(i) << endl;
  //  cout<<"Cout using << operator"<<endl;
    cout<<array1<<array2<<array3<<endl;
	return 0;
}