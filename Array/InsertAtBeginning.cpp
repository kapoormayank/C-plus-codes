// Insert the element in Array Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// Function to print the array
void printArray(vector<int>& arr) {
    for(int num:arr) {
        cout<<num<<" ";
    }
    cout<<endl;
}

// Function to insert the first element in array
void insertAtBeginning(vector<int>& arr,int n,int m) {
    arr.insert(arr.begin(),m);
}

// Main function
int main() {
    int n,m;
    cout<<"Enter size of first array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Print the first array: ";
    printArray(arr);
    cout<<"Enter element for insert at beginning: ";
    cin>>m;
    insertAtBeginning(arr,n,m);
    cout<<"Insert element in array at beignning: ";
    printArray(arr);
    return 0;
}

