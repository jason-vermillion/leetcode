// https://leetcode.com/problems/smallest-string-with-swaps/
// 1202. Smallest String With Swaps
// TODO: revisit
// union find
class Solution {
public:
    int find(vector<int>& ds, int i) {
        int result;
        
        if (ds[i] < 0) {
            result = i;
        }
        else {
            ds[i] = find(ds, ds[i]);
            result = ds[i];
        }
        return result;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> ds(n, -1);
        vector<vector<int>> m(n);
        
        for (auto& p : pairs) {
            auto i = find(ds, p[0]), j = find(ds, p[1]);
            if (i != j) {
                ds[j] = i;   
            }
        }
        
        for (auto i = 0; i < n; ++i) {
            m[find(ds, i)].push_back(i);  
        }
          
        for (auto &ids : m) {
            string ss = "";
            for (auto id : ids) 
                ss += s[id];
            sort(begin(ss), end(ss));
            for (auto i = 0; i < ids.size(); ++i) 
                s[ids[i]] = ss[i];
        }
        return s;
    }
};