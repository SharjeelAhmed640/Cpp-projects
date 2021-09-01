// Overload ++ when used as prefix and postfix

#include <iostream>
using namespace std;

class Count {
   private:
    int value;

   public:


    Count(int x=0) {value=x;}



    int operator ++ () {
        int temp(0); 
        value=value*4;
        temp=value;
        return temp;
    }



    int operator ++ (int) {
        int temp(0); 
        value=value/4;
        temp=value;
        return temp;
    }

   
    int display(){
        return value;
    }
};

int main() {
    int n;
    cout<<"Enter int : ";
    cin>>n;
    Count count1(n);


    count1++;
    cout<<"After post -- operator : "<<count1.display()
    <<endl;

    ++count1;
    cout<<"After pre -- operator : "<<count1.display()
    <<endl;
    
    return 0;
}

