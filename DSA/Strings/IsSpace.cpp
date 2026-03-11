// Check String has Space Or not Algorithm Implementation In C++
#include<iostream>
#include<string>
#include<cctype> // For isspace()
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    // Print original string
    cout<<"Original String: "<<str<<endl;
    bool hasSpace=false;
    // Loop to check if there is any space
    for(int i=0;i<str.length();i++) {
        // isspace is built in keyword/function
        if(isspace(str[i])) {  // Checks if character is a space or whitespace
            hasSpace=true;
            break;
        }
    } 
    if(hasSpace) {
        cout<<"Yes, the string has space...."<<endl;
    }else {
        cout<<"No, the string has no space!!!!"<<endl;
    }
    return 0;
}
