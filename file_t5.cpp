// C++ program to demonstrate read/write of class
// objects in C++.
#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

// Class to define the properties
class participant {
	char Name[20];
	int Age, Ratings;
public:

	// Instance variables

	// Function declaration of input() to input info
	int input();

	// Function declaration of output_highest_rated() to
	// extract info from file Data Base
	int max();
    int output(int id);
};

// Function definition of input() to input info
int participant::input()
{
	// Object to write in file
	ofstream file;

	// Opening file in append mode
	file.open("participant.txt", ios::app);
    participant obj;
    cout<<"Enter name : ";
    cin>>obj.Name;
    cout<<"Enter id : ";
    cin>>obj.Age;
    cout<<"Enter score : ";
    cin>>obj.Ratings;
	// Object of class contestant to input data in file
	file.write((char*)&obj, sizeof(obj));
    file.close();

}

// Function definition of output_highest_rated() to
// extract info from file Data Base
int participant::max()
{
	// Object to read from file
	ifstream file;

	// Opening file in input mode
	file.open("participant.txt", ios::in);

	// Object of class contestant to input data in file
	participant obj;

	// Reading from file into object "obj"
	file.read((char*)&obj, sizeof(obj));

	// max to store maximum ratings
	int high = 0;

	// Highest_rated stores the name of highest rated contestant
	string Highest_rated;

	// Checking till we have the feed
	while (!file.eof()) {
		// Assigning max ratings
		if (obj.Ratings > high) {
			high = obj.Ratings;
			Highest_rated = obj.Name;
		}

		// Checking further
		file.read((char*)&obj, sizeof(obj));
	}

	// Output is the highest rated contestant
	cout << Highest_rated<<"\t"<<high<<endl;
	return 0;
}
int participant::output(int id)
{
	// Object to read from file
	ifstream file;

	// Opening file in input mode
	file.open("participant.txt", ios::in);

	// Object of class contestant to input data in file
	participant obj;

	// Reading from file into object "obj"
	file.read((char*)&obj, sizeof(obj));

	
	// Checking till we have the feed
	while (!file.eof()) {
		// Assigning max ratings
		if (obj.Age == id) {
            cout<<"Name : "<<obj.Name<<"  ID : "<<obj.Age<<" Score : "<<obj.Ratings<<endl;
            file.close();
            break;
		}

		// Checking further
		file.read((char*)&obj, sizeof(obj));
	}

	return 0;
}
// Driver code
int main()
{
    char name[20];
    int id,score;
 
	// Creating object of the class
	participant object;

	// Inputting the data
	object.input();

	// Extracting the max rated contestant
	object.max();
    cout<<"enter id to search : ";
    cin>>id;
    object.output(id);


	return 0;
}
