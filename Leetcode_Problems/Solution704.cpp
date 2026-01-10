// Leetcode Problem Number 704
#include<iostream>
using namespace std;

// Function To Print An Array
void printArray(int nums[],int k){
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;;
}

// Function To Find The Target Element Index
int search(int nums[],int k,int target){
    for(int i=0;i<k;i++){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
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
    cout<<"Enter Target Element: ";
    int target;
    cin>>target;
    int result=search(nums,k,target);
    if(result!=-1){
        cout<<"Target Element Index Is : "<<result<<endl;
    }
    else{
        cout<<"Target Element Not Exist In The Array"<<endl;
    }
    return 0;
}
