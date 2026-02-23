// LeetCode Problem 349: Intersection of Two Arrays
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the intersection of two arrays
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> resultSet;
    
    for (int num : nums2) {
        if (set1.count(num)) {
            resultSet.insert(num);
        }
    }
    
    return vector<int>(resultSet.begin(), resultSet.end());
}

// Main function
int main() {
    int n, m;
    cout << "Enter the size of nums1 and nums2: ";
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }
    vector<int> result = intersection(nums1, nums2);
    cout << "Intersection of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

