// C++ program to demonstrate Abstration using Interfaces
#include<iostream>
using namespace std;

// Base class (Interface)
class Shape{
    public: //Access specifier or modifier
    //  Pure virtual Function
    virtual float area()=0;
};

// Derived class
class Rectangle : public Shape{
    float length; //Data members
    float breadth;
    public:
    // Constructor
    Rectangle(float l,float b):length(l),breadth(b){}
    // Using pure virtual function
    float area(){
        return length*breadth;
    }
};

// Main function
int main(){
    Shape* shape=new Rectangle(10.5f,5.5f);
    cout<<"\n-- Abstraction using Interface in C++ --"<<endl;
    cout<<"Area of Rectangle is: "<<shape->area()<<endl;
    return 0;
}


