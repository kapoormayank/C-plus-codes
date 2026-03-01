// LeetCode Problem 3857: Minimum Cost to Split Into Ones
#include<iostream>
using namespace std;
// Function to find the minimum cost
int minCost(int n) {
    return n*(n-1)/2;
}

// Main function
int main() {
    cout<<"Enter a number : ";
    int n;
    cin>>n;
    cout<<"Minimum Cost to split into ones : "<<minCost(n)<<endl;;
    return 0;
}

