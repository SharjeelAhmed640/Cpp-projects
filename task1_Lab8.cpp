#include<iostream>
using namespace std;

class animal{
    public:
    void animalSound(){
        cout<<"The animal makes a sound"<<endl;
    }
};
class cat{
    public:
    void animalSound(){
        cout<<"The cat says meow."<<endl;
    }
};
class dog{
    public:
    void animalSound(){
        cout<<"The dog says bow wow"<<endl;
    }
};
class duck{
    public:
    void animalSound(){
        cout<<"The duck says quack quack"<<endl;
    }
};
int main()
{
    animal human;
    dog tommy;
    cat smoky;
    duck daffy;
    human.animalSound();
    tommy.animalSound();
    smoky.animalSound();
    daffy.animalSound();
}