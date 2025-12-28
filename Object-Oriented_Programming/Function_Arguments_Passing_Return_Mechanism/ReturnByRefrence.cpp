// Return by refrence example in C++
#include<iostream>
using namespace std;

// Return by refrence function
int& fun(int& x){
    return x;
}

// Main function
int main(){
    int a=10;
    int &ref=fun(a);
    cout<<"Value of a before modification: "<<ref<<endl;
    a=20;
    cout<<"Value of a after modification: "<<ref<<endl;
    return 0;
}

