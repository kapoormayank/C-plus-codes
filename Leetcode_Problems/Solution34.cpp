// Leetcode Problem 34: Find First and Last Position of Element in Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;  // search left side
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;  // search right side
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);

    cout << "First and last position of " << target 
         << " in the array: [" << result[0] 
         << ", " << result[1] << "]" << endl;

    return 0;
}
