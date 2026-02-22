// Leetcode 119: Pascal's Triangle II
#include <iostream>
#include <vector>
using namespace std;

// Class to find the row of Pascal's Triangle
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize the row with 1's
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1]; // Update the current element by adding the previous element
            }
        }
        return row;
    }
};

// Main function
int main() {
    Solution solution;
    int rowIndex = 3; // Example row index
    vector<int> result = solution.getRow(rowIndex);
    cout << "Row " << rowIndex << " of Pascal's Triangle: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
