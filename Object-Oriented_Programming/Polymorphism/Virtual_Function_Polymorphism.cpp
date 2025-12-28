// C++ program to demonstrate Polymorphism using Virtual Functions
#include<iostream>
#include<string>
using namespace std;

// Base class
class Vehicle{
    protected:
    string brand;
    string model;
    int year;
    public:
    Vehicle(string x,string y,int z){
        this->brand = x;
        this->model = y;
        this->year = z;
    }
    // Virtual Function
    virtual void details(){
        cout<<"Brand of vechicle : "<<this->brand<<endl;
        cout<<"Model of vechicle : "<<this->model<<endl;
        cout<<"Year of vechicle : "<<this->year<<endl<<endl;
    } 
};

// Derived class
class Car : public Vehicle {
    float mileage;
    public:
    Car(string x,string y,int z,float mileage): Vehicle(x,y,z),mileage(mileage){
    }
    void details() override{
        cout<<"Car name : "<<model<<endl;
        cout<<"Brand of car : "<<brand<<endl;
        cout<<"Year of car : "<<year<<endl;
        cout<<"Mileage of car : "<<mileage<<endl<<endl;
    }
};

// Main function
int main(){
    // Parent class object refers to child class object
    cout<<"\n-- Virtual Function Polymorphism --"<<endl<<endl;
    Vehicle* car2 = new Car("Ford","Mustang",2021,10.5f);
    car2->details();
    
    //Never parent class cannot inherit from the child class
    // Car* car3 = new Vehicle("BMW","X5",2022);
    // car3->details();
    return 0;
}