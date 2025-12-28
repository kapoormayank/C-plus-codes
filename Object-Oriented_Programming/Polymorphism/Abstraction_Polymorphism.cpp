// C++ Program to Illustrate Abstraction and Polymorphism
#include<iostream>
using namespace std;

//Base class
class Parent{
    public:
    string name;
    int age;
    // Pure Virtual Function
    virtual void details()=0;
};

// Derived class
class Child : public Parent{
    public:
    float weigth; //Derived class members
    float height;
    Child(string name,int age,float weigth,float height){
        this->name=name;
        this->age=age; //Base class member
        this->weigth=weigth;
        this->height=height;
    }
    // Overriding the pure virtual function
    void details() override{
        cout<<"Name of Child : "<<name<<endl;
        cout<<"Age of Child : "<<age<<endl;
        cout<<"Weight of Child : "<<weigth<<endl;
        cout<<"Height of Child : "<<height<<endl;
    }
};

//Main Function
int main(){
    // Parent class pointer refers to child class object
    cout<<"\n-- Polymorphism using Abstraction --"<<endl<<endl;
    Parent* c1 = new Child("Mayank Roy Kapoor",20,75.9f,5.11f); //Dynamic Memory Allocation
    c1->details();
    return 0;
}