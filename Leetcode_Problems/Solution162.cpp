// Leetcode Problem Number 162
#include<iostream>
using namespace std;

// Function To Print An Array
void printArray(int nums[],int k){
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;;
}

// Function To Find the Peak Index From Array Elements
int findPeakElement(int nums[],int k){
    int big=0;
    for(int i=0;i<k;i++){
        if(nums[i]>nums[big]){
            big=i;
        }
    }
    return big;
}

// Main function
int main(){
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    int nums[n];
    cout<<"Enter Elements In An Array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Original Array Print: ";
    int k=sizeof(nums)/sizeof(nums[0]);
    printArray(nums,k);
    int result=findPeakElement(nums,k);
    cout<<"Peak Element Index From The Array: "<<result<<endl;
    return 0;
}
