#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class vehicle{
    protected:
    string type,model,make,color;
    int year,milesdriven;
    public:
    vehicle(string type,string model,string make,string color,int year,int milesdriven)
    {
        this->type=type;
        this->model=model;
        this->make=make;
        this->color=color;
        this->year=year;
        this->milesdriven=milesdriven;
    }
};
class Gasvehicle: public virtual vehicle{
    protected:
    int fuelTankSize;
    public:
    Gasvehicle(int fuelTankSize,string type,string model,string make,string color,int year,int milesdriven):vehicle(type,model,make,color,year,milesdriven)
    {
        this->fuelTankSize=fuelTankSize;
    }
};
class electricvehicle: public virtual vehicle{
    protected:
    int energystorage;
    public:
    electricvehicle(int energystorage,string type,string model,string make,string color,int year,int milesdriven):vehicle(type,model,make,color,year,milesdriven)
    {
        this->energystorage=energystorage;
    }
};
class heavyvehicle:public electricvehicle,public Gasvehicle{
    protected:
    int Maxweight,NoOfWheels,length;
    public:
    heavyvehicle(int Maxweight,int NoOfWheels,int length,int energystorage,int fuelTankSize,string type,string model,string make,string color,int year,int milesdriven)
    :electricvehicle(energystorage,type,model,make,color,year,milesdriven),Gasvehicle(fuelTankSize,type,model,make,color,year,milesdriven),vehicle(type,model,make,color,year,milesdriven)
    {
        this->Maxweight=Maxweight;
        this->NoOfWheels=NoOfWheels;
        this->length=length;
    }
};
class constructiontruck:public heavyvehicle{
    string cargotype;
    public:
    constructiontruck(string cargotype,int Maxweight,int NoOfWheels,int length,int energystorage,int fuelTankSize,string type,string model,string make,string color,int year,int milesdriven)
    :heavyvehicle(Maxweight,NoOfWheels,length,energystorage,fuelTankSize,type,model,make,color,year,milesdriven),vehicle(type,model,make,color,year,milesdriven)
    {
        this->cargotype=cargotype;
    }
};
class bus:public heavyvehicle{
    int NoOfSeats;
    public:
    bus(int NoOfSeats, int Maxweight,int NoOfWheels,int length,int energystorage,int fuelTankSize,string type,string model,string make,string color,int year,int milesdriven )
    :heavyvehicle(Maxweight,NoOfWheels,length,energystorage,fuelTankSize,type,model,make,color,year,milesdriven),vehicle(type,model,make,color,year,milesdriven)
    {
        this->NoOfSeats=NoOfSeats;
    }
    void display()
    {
        cout<<"Type : "<<type<<endl
        <<"Model : "<<model<<endl
        <<"Make : "<<make<<endl
        <<"color : "<<color<<endl
        <<"Year : "<<year<<endl
        <<"Miles driven : "<<milesdriven<<endl
        <<"Max weight : "<<Maxweight<<endl
        <<"No of wheels : "<<NoOfWheels<<endl
        <<"Length : "<<length<<endl
        <<"nergy storage : "<<energystorage<<endl
        <<"fuel tank size : "<<fuelTankSize<<endl
        <<"No of seats : "<<NoOfSeats<<endl;
    }
};
class HighPerformance:public Gasvehicle{
    protected:
    double hoursepower,highspeed;
    public:
    HighPerformance(double hoursepower,double highspeed,int fuelTankSize,string type,string model,string make,string color,int year,int milesdriven)
    :Gasvehicle(fuelTankSize,type,model,make,color,year,milesdriven),vehicle(type,model,make,color,year,milesdriven)
    {
        this->hoursepower=hoursepower;
        this->highspeed=highspeed;
    }
};
class sportscar:public HighPerformance{
    string gearbox,drivensystem;
    public:
    sportscar(string gearbox,string drivensystem,double hoursepower,double highspeed,int fuelTankSize,string type,string model,string make,string color,int year,int milesdriven)
    :HighPerformance(hoursepower,highspeed,fuelTankSize,type,model,make,color,year,milesdriven),vehicle(type,model,make,color,year,milesdriven)
    {
        this->gearbox=gearbox;
        this->drivensystem=drivensystem;
    }
};
int main()
{
bus b(5,199,6,30,85,45,"BUS","2021kfp","TOYOTA","WHITE",65,5645);
b.display();
return 0;
}