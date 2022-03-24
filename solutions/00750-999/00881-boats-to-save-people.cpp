// https://leetcode.com/problems/boats-to-save-people/
// 881. Boats to Save People
// Time complexity O(NLogN)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        int i = 0, j = n - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            }
            else {
                j--;
            }
            count++;
        }
        
        return count;
    }
};