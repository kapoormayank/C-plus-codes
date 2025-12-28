// Destructor in C++ is a special member function that is automatically invoked 
// When an object goes out of scope or is explicity deleted.
#include<iostream>
using namespace std;

// Class with a destructor
class Sample{
    public:
    // Constructor
    Sample(){
        cout<<"Constructor Called"<<endl;
    }
    // Destructor
    ~Sample(){
        cout<<"Destructor Called"<<endl;
    }
};

// Main function
int main(){
    Sample s;
    return 0;
}

