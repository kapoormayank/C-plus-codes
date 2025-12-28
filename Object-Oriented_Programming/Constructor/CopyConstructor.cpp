// Copy Constructor Example in C++
#include<iostream>
using namespace std;

// Class with a copy consructor
class Demo{
    public: // Access specifier or modifier
    int x; // Data members
    // Constructor
    Demo(int val){
        this->x=val; //Parameterized Constructor
    }

    // Copy Constructor
    Demo(const Demo &d){
        this->x=d.x;
    }
    void display(){
        cout<<"Value of x: "<<this->x<<endl;
    }
};

// Main function
int main(){
    Demo d1(10); //Calls parameterized constructor
    Demo d2=d1; // Invokes copy constructor
    d2.display();
    return 0;
}
