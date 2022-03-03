// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newSize = nums.size();
        int prevIndex = 0;
        int prevCount = 0;
        int sz = nums.size();
        int delCount = 0;
        
        // edge cases
        if (sz < 3) {
            return sz;
        }
        
        prevIndex = 0;
        prevCount = 1;
        
        // mark all the dups to delete
        for (int i = 1; i < sz; ++i) {
            if (nums[i] == nums[prevIndex]) {
                if (prevCount > 1) {
                    nums[i] = INT_MIN;
                    delCount++;
                }
                else {
                    prevCount++;
                }
            }
            else {
                prevIndex = i;
                prevCount = 1;
            }
        }
        newSize = nums.size() - delCount;
        
        removeGaps(nums);
        
        return newSize;
    }
private:
    // remove the gaps in the array.
    void removeGaps(vector<int>& nums) {
        // find the first empty element
        int ePos = -1;
        int i = 0;
        while(i < nums.size()) {
            if (nums[i] == INT_MIN) {
                ePos = i;
                break;
            }
            i++;
        }
        
        // no gaps in the list
        if (ePos < 0) return;
        
        // find the non-empty elements and shift them down
        for (int i = ePos + 1; i < nums.size(); ++i) {
            if (nums[i] != INT_MIN) {
                nums[ePos] = nums[i];
                nums[i] = INT_MIN;
                ePos++;
            }
        }
    }
    
    void printArray(vector<int>& nums) {
        int sz = nums.size();
        cout << "[";
        for (int i = 0; i < sz; ++i) {
            cout << nums[i];
            if (i < sz - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
};