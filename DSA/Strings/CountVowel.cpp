// Count The Vowels from String Algorithm Implementation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Main function
int main() {
    string str;
    cout<<"Enter a string: ";
    // getline help to read to whole string without breaking..
    getline(cin,str);
    // Count numbers of vowels from String
    int count=0;
    for(int i = 0; i < str.length(); i++) {
         if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') {
            count++;
        }
        else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }
    cout<<"String has "<<count<<" numbers of vowels...."<<endl;
    return 0;
}


