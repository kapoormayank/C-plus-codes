// C++ program to demonstrate Call By Value
#include<iostream>
using namespace std;

// Function to demonstrate Call By Value
void add(int a,float b,string str){
    cout<<"First Number: "<<a<<endl;
    cout<<"Second Number: "<<b<<endl;   
    cout<<"String : "<<str<<endl;   
}

// Main function
int main(){
    int x=56;
    float y=45.67f;
    string name="Hello";

    // Call By Value
    add(x,y,name);
    return 0;
}
