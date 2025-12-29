// C++ program to demonstrate Access Modifiers
#include<iostream>
using namespace std;

// Access Modifiers in C++
class Demo{
    int a = 954;
    private:
    int x = 343;
    protected:
    int y = 56;
    public:
    int z = 89;
    void show(){
        cout<<"Default Datatype : "<<a<<endl;
        cout<<"Private datatype value : "<<x<<endl;
        cout<<"Protected datatype value : "<<y<<endl;
        cout<<"Public datatype value : "<<z<<endl;
    }
    
    // Setter function to set private data member
    void setx(int val){
        this->x=val;
    }
    public:
    int getx(){
        return x;
    }
    //Getter function to access protected data memeeber
    
    int gety(){
    return y;
    }
};

// Main function
int main(){
    Demo obj;
    obj.show();
    cout<<"\nPrivate datatype : "<<obj.getx()<<endl;
    cout<<"Protected datatype : "<<obj.gety()<<endl;
    cout<<"Public datatype : "<<obj.z<<endl;
    return 0;
}