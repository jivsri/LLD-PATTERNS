#include<bits/stdc++.h>
using namespace std;


// it can happen that many children have same code for 
// the inherited behaviour

class driveStrategy{
    public:
    virtual void drive()=0;
};

class NormalDriveStrategy:public driveStrategy{
    public:
    void drive(){
        cout<<"Normal Drive Strategy"<<endl;
    }
};

class OffRoadDriveStrategy:public driveStrategy{
    public:
    void drive(){
        cout<<"Off Road Drive Strategy"<<endl;
    }
};

class Vehicle{
    driveStrategy * ptr;
    public:
    Vehicle(driveStrategy *obj){
        ptr=obj;
    }

    void drive(){
        ptr->drive();
    }
};

class NormalVehicle:public Vehicle{
    public:
    NormalVehicle():Vehicle(new NormalDriveStrategy()){}
};

class SportVehicle:public Vehicle{
    public:
    SportVehicle():Vehicle(new OffRoadDriveStrategy()){}
};



int main(){

    Vehicle *veh=new SportVehicle();
    veh->drive();
    veh=new NormalVehicle();
    veh->drive();

    return 0;
}