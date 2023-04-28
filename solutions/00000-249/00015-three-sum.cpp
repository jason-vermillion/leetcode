// https://leetcode.com/problems/3sum/description/
// 15. 3Sum
// 00015-3-sum.cpp

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        map<int, int> freq;
        vector<int> uniqueSorted;

        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            freq[nums[i]]++;
        }

        for (auto itr = freq.begin(); itr != freq.end(); ++itr)
        {
            // list of unique values
            uniqueSorted.push_back(itr->first);
        }

        // 0 + 0 + 0 = 0 edge case
        if (freq[0] > 2)
        {
            result.push_back(triplet(0, 0, 0));
        }

        for (int i = 0, n = uniqueSorted.size(); i < n - 1; ++i)
        {
            int a = uniqueSorted[i];
            for (int j = i + 1; j < n; ++j)
            {
                int b = uniqueSorted[j];
                int sum = a + b;
                int c = -sum;

                // a + b + c = 0
                if (c > b && freq[c] > 0)
                {
                    result.push_back(triplet(a, b, c));
                }

                // 2a + b = 0
                if (freq[a] > 1 && 2 * a + b == 0)
                {
                    result.push_back(triplet(a, a, b));
                }

                // a + 2b = 0
                if (freq[b] > 1 && a + 2 * b == 0)
                {
                    result.push_back(triplet(a, b, b));
                }
            }
        }

        return result;
    }

    vector<int> triplet(int a, int b, int c)
    {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        return v;
    }
};