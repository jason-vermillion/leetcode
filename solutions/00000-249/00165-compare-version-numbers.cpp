// https://leetcode.com/problems/compare-version-numbers/
// 165. Compare Version Numbers
class Solution {
private:
    struct Version {
        int revisionCount;
        vector<int> revisions;
    };
    
    Version parseVersion(string version) {
        Version v;
        int sz = version.size();
        int vIndex = 0;
        bool isParsingToken = false;
        v.revisions = vector<int>(500,0);
        v.revisionCount = 0;
        
        int x = 0;
        for (int i = 0; i < sz; ++i) {
            if (version[i] == '.') {
                v.revisions[vIndex] = x;
                v.revisionCount++;
                x = 0;
                vIndex++;
                isParsingToken = false;
            }
            else {
                x = x * 10 + version[i] - '0';
                isParsingToken = true;
            }
        }
        
        if (isParsingToken) {
            v.revisions[vIndex] = x;
            v.revisionCount++;
        }
        
        return v;
    };
public:
    int compareVersion(string version1, string version2) {
        int n = 0;
        int result = 0;
        
        Version a = parseVersion(version1);
        Version b = parseVersion(version2);
        n = max(a.revisionCount, b.revisionCount);
        
        for (int i = 0; i < n; ++i) {
            if (a.revisions[i] < b.revisions[i]) {
                result = -1;
                break;
            }
            else if (a.revisions[i] > b.revisions[i]) {
                result = 1;
                break;
            }
        }
        
        return result;
    }
};