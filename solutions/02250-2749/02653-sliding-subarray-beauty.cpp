// https://leetcode.com/problems/sliding-subarray-beauty/
// 2653. Sliding Subarray Beauty
// 02653-sliding-subarray-beauty.cpp

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        vector<int> result;
        map<int, int> freq;
        int n = nums.size();

        for (int start = 0, end = 0; end < n; ++end)
        {
            int a = min(nums[end], 0);
            freq[a]++;
            if (end >= k - 1)
            {
                int count = 0;
                for (auto it = freq.begin(); it != freq.end(); ++it)
                {
                    // map key
                    int val = it->first;
                    // map value
                    count += it->second;
                    if (count >= x)
                    {
                        result.push_back(val);
                        break;
                    }
                }
                freq[nums[start]]--;
                start++;
            }
        }
        return result;
    }
};
