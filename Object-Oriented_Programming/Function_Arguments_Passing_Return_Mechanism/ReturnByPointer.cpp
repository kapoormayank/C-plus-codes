// Return by Pointer example in C++
#include<iostream>
using namespace std;

// Return by pointer function
int* display(int& x){
    return &x;
}

// Main function
int main(){
    int a=10;
    int* print=display(a);
    cout<<"Value of a using pointer : "<<*print<<endl;
    a=20;
    cout<<"Value of a after modification using pointer : "<<*print<<endl;
    return 0;
}

