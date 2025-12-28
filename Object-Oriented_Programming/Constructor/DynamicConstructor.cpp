// Dynamic Constructor Example in C++
#include<iostream>
using namespace std;

// Class with a dynamic constructor
class Sample{
    public:
    int data;
    // Dynamic Constructor
    Sample(int val){
        this->data=val;
    }
    void display(){
        cout<<"Value of data: "<<this->data<<endl;
    }
};

// Main function
int main(){
    Sample s1(5);
    s1.display();
    return 0;
}
