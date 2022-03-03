// https://leetcode.com/problems/sort-list/
// 148. Sort List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* curr;
        ListNode* prev;
        ListNode* newHead;
        
        
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        curr = head;
        while(curr != nullptr) {
            nums.push_back(curr -> val);
            curr = curr -> next;
        }
        
        sort(nums.begin(), nums.end());
        
        prev = nullptr;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            curr = new ListNode(nums[i]);
            if (prev != nullptr) {
                prev -> next = curr;
            }
            else {
                newHead = curr;
            }
            prev = curr;
        }
        
        return newHead;
    }
};