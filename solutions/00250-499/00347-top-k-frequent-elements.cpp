// https://leetcode.com/problems/top-k-frequent-elements/
// 347. Top K Frequent Elements
// Time complexity O(N log N)
// Space complexity O(N + k)
// TODO: revisit quick select
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> freq;
        priority_queue<pair<int,int>> q;
        
        for (auto& val : nums) {
            freq[val]++;
        }
        
        for (auto ele : freq) {
            int val = ele.first;
            int count = ele.second;
            
            // flip the sign of the count so that least frequent item is at the top of the priority_queue
            if (q.size() < k) {
                q.push(make_pair(-count, val));
            }
            else {
                int t = -q.top().first;
                
                if (count > t) {
                    q.pop();
                    q.push(make_pair(-count, val));
                }
            }
        }
        
        while(q.size() > 0) {
            result.push_back(q.top().second);
            q.pop();
        }
        
        return result;
    }
};