// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// character frequency and sliding window method.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        vector<int> res;
        vector<int> freqP(26, 0); // character count for chars in p
        vector<int> freqWord(26, 0); // character count for each word of length p
        int wordStart = 0;
        
        // handle edge cases
        if (pSize > sSize || pSize == 0 || sSize == 0) {
            return res;
        }
        
        // initialize the character frequency vectors.
        for (int i = 0; i < pSize; i++) {
            freqP[p[i] - 'a']++;
            freqWord[s[i] - 'a']++;
        }
        
        if (freqWord == freqP) {
            res.push_back(wordStart);        
        }
        
        // sliding window through s
        for (int i = pSize; i < sSize; ++i) {
            freqWord[s[wordStart] - 'a']--;
            
            wordStart++;
            freqWord[s[i] - 'a']++;
            
            if (freqWord == freqP) {
                res.push_back(wordStart);        
            }            
        }
        
        return res;
    }
};


// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// brute method - TLE
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        string k;
        vector<int> res;
        
        // sorted list of letters in p.
        k = p;
        sort(k.begin(), k.end());
        
        // check all of the substrings of length p in string s.
        for (int i = 0; i + pSize <= sSize; ++i) {
            string sub;
            for (int j = 0; j < pSize; ++j) {
                sub.push_back(s[i+j]);
            }
            sort(sub.begin(), sub.end());
            if (sub == k) {
                res.push_back(i);
            }
        }
        
        return res;
        
    }
};