// Call by Refrence in C++
#include<iostream>
using namespace std;

// Function to demonstrate Call by Refrence
void add(int &a,int &b){
    a+=10;
    b+=10;
}

// Main function
int main(){
    int a=10,b=20;
    add(a,b);
    cout<<"Value of a using refrence : "<<a<<endl;
    cout<<"Value of b using refrence : "<<b<<endl;
    return 0;
}

