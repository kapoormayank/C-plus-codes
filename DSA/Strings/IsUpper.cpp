// Check String is Upper or not Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Function to check uppercase
bool isUpperCase(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(isalpha(str[i]) && !isupper(str[i])) {
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    if(isUpperCase(str)) {
        cout<<"String is uppercase.... "<<endl;
    }else {
        cout<<"String is not uppercase...."<<endl;
    }
    return 0;
}


