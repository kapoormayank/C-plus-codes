// C++ program to demonstrate all types of Inheritance
#include<iostream>
using namespace std;

// Base Class
class Animal{
    public:
    void eat(){
        cout<<"This animal eats food."<<endl;
    }
};

// Derived class(Single Inheritance)
class Dog : public Animal{
    public:
    void bark(){
        cout<<"The dog are bark."<<endl;
    }
};

// Derived class(Multilevel Inheritance)
class Puppy : public Dog{
    public:
    void flexibity(){
        cout<<"Puppy is very flexible!"<<endl;
    }
};

// Another Base class for Multiple Inheritance
class Speed{
    public:
    void speed(){
        cout<<"Speed of animal!"<<endl;
    }
};

// Derived class(Multiple Inheritance)
class fitness : public Animal,public Speed{
    public:
    void fast(){
        cout<<"Fast animal!"<<endl;
    }
};

// Main function
int main(){
    // Single Inheritance
    cout<<"\n-- Single Inheritance --"<<endl;
    Dog dog; //Static Memory Allocation
    dog.eat();
    dog.bark();
    // Multilevel Inheritance
    cout<<"\n-- Multilevel Inheritance --"<<endl;
    Puppy p1; //Static Memory Allocation
    p1.eat();
    p1.bark();
    p1.flexibity();
    // Multiple Inheritance
    cout<<"\n-- Multiple Inheritance --"<<endl;
    fitness f1; //Static Memory Allocation
    f1.eat();
    f1.speed();
    f1.fast();
    return 0;
}

