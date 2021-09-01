/*Task - 03:
Write a program that reads a student name followed by five test scores. The program should output
the student name, the five test scores, and the average test score. Output the average test score
with two decimal places.*/

#include<iostream> 
#include<iomanip> 
using namespace std ;

int main (){
	
	string name ;
	float score[5] ;
	cout<< "Enter the name of the student : " ;
	getline (cin , name) ;
	cout<< "Enter the test score "<<endl ;
	for( int i = 0 ; i < 5 ; i++) {
		
        cout<<i+1<<" score : ";
		cin >> score[i] ;
		
	}
	
	float avg  = 0 ;
	
	for(int i = 0 ; i < 5 ; i++){\
	
	  avg = score[i] + avg  ; 	
	}
	
	avg = avg / 5 ;
	
	cout << "\n\n\nStudent name   " << name << endl << "Test Score " <<endl ;
	
	
	for( int  i = 0 ; i < 5 ; i++) {
		
        cout<<i+1<<" score : ";
		cout << score[i]<<endl;
		
	}
	
	cout  <<"Average Test score  " << setprecision(2) << fixed << avg ;




}