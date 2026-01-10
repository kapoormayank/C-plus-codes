// Leetcode Problem Number 167
#include<iostream>
#include<vector>
using namespace std;

// Function To Print An Array
void printArray(int nums[],int k){
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;;
}

// Function To Find The Target Element Index
vector<int> twoSum(int nums[],int k,int target){
    for(int i=0;i<k;i++){
        int n=nums[i];
        for(int j=i+1;j<k;j++){
            int sum=n+nums[j];
            if(sum==target){
                return {i+1,j+1};
            }
        }
    }
    return {-1,-1};
}

// Function To Print To Vector
void printVector(const vector<int>& v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
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
    vector<int> result=twoSum(nums,k,target);
    cout<<"Indexes";
    printVector(result);
    return 0;
}
