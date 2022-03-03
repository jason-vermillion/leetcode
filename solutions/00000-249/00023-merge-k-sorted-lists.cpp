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
// https://leetcode.com/problems/merge-k-sorted-lists/submissions/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        ListNode* curr = nullptr;
        ListNode* head = nullptr;
        
        for(auto l : lists) {
            ListNode* curr = l;
            while(curr != nullptr) {
                vals.push_back(curr -> val);
                curr = curr -> next;
            }
        }
        
        sort(vals.begin(), vals.end());
        
        for (auto v : vals) {
            if (head == nullptr) {
                curr = new ListNode(v);
                head = curr;
            }
            else {
                curr -> next = new ListNode(v);
                curr = curr -> next;
            }
        }
        
        return head;
        
    }
};





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
// https://leetcode.com/problems/merge-k-sorted-lists/submissions/
// Merging n lists in a loop - TLE
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        ListNode* head = nullptr;
        
        for(auto l : lists) {
            head = merge(head, l);
        }
                
        return head;
    }
private:    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* tail = nullptr;
        ListNode* dummy;
        ListNode* smallest;
        ListNode* c1;
        ListNode* c2;
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        dummy = new ListNode();
        tail = dummy;
        c1 = list1;
        c2 = list2;
        
        while (c1 != nullptr || c2 != nullptr) {
            if (c1 == nullptr || (c2 != nullptr && c2 -> val <= c1 -> val)) {
                smallest = new ListNode(c2 -> val);
                c2 = c2 -> next;
            }
            else {
                smallest = new ListNode(c1 -> val);
                c1 = c1 -> next;
            }
            
            tail -> next = smallest;
            tail = smallest;
        }
        
        return dummy -> next;      
    }

    void printList(ListNode* list) {
        ListNode* t = list;
        cout << "[";
        while (t != nullptr) {
            cout << t -> val;
            if (t -> next != nullptr) {
                cout << ",";
            }
            t = t -> next;
        }
        cout << "]\n";
    }

};