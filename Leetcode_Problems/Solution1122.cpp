// LeettCode Problem 1122: Relative Sort Array
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to sort arr1 according to the order defined by arr2
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> countMap;
    // Count frequencies of arr1
    for (int num : arr1) {
        countMap[num]++;
    }
    vector<int> result;
    // Add elements in arr2 order
    for (int num : arr2) {
        while (countMap[num] > 0) {
            result.push_back(num);
            countMap[num]--;
        }
    }
    // Collect remaining elements
    vector<int> remaining;
    for (auto& pair : countMap) {
        while (pair.second > 0) {
            remaining.push_back(pair.first);
            pair.second--;
        }
    }
    // Sort remaining elements
    sort(remaining.begin(), remaining.end());
    // Append remaining
    result.insert(result.end(), remaining.begin(), remaining.end());
    return result;
}

// Main function
int main() {
    int n, m;
    cout << "Enter the size of arr1 and arr2: ";
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    cout << "Enter the elements of arr1: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cout << "Enter the elements of arr2: ";
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }
    vector<int> result = relativeSortArray(arr1, arr2);
    cout << "Relative sorted array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
