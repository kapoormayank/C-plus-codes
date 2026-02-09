// Leetcode Problem 23: Merge k Sorted Lists

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list using class
class ListNode {
    // Default Access Modifier
    public:
    // Data Members
    int val;
    ListNode* next;
    // Parameterized Constructor
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    // Main function to merge k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeSort(lists, 0, lists.size() - 1);
    }

private:
    // Divide & conquer (merge sort)
    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high) {
        if (low == high) {
            return lists[low];
        }
        int mid = low + (high - low) / 2;
        ListNode* l1 = mergeSort(lists, low, mid);
        ListNode* l2 = mergeSort(lists, mid + 1, high);

        return mergeTwoLists(l1, l2);
    }

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};

// Main function
int main() {
    // Create input lists: [[1,4,5],[1,3,4],[2,6]]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);
    cout<<"Merge k sorted lists: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}

