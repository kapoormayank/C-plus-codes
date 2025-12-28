// C++ program to demonstrate Abstraction 
#include<iostream>
using namespace std;

// Base class
class Parent{
    public: // Access specifier or modifier
    string name;
    int age;
    // Pure Virtual Function
    virtual void details()=0;
};

// Derived class
class Child : public Parent{
    public:
    // Constructor
    Child(string n,int a){
        this->name=n;
        this->age=a;
    }
    // Member function
    void information(){
        cout<<"Information About Child Are : "<<endl;
    }
    // Overriding the pure virtual function of base class
    void details() override{
        cout<<"Name of Child : "<<name<<endl;
        cout<<"Age of Child : "<<age<<endl;
    }
};

// Main function
int main(){
    // Child object and child class
    cout<<"\n-- Child class object --"<<endl;
    Child* c1 = new Child("Mayank",72); //Dynamic Memory Allocation
    c1->information();
    c1->details();
    return 0;
}