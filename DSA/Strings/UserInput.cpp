// User Input String Algorithm Implementation In C++

#include<iostream>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    cout<<"User Input String is: "<<str<<endl;
    return 0;
}
