// https://leetcode.com/problems/combination-sum/
// recursion with backtracking
// time complextity O(2^N)
class Solution {
private:
    struct State {
        vector<int> nums;
        vector<int> currSequence;
        vector<vector<int>> output;
    };
    
public:
    void findCombinations(int i, int k, State& state)
    {
        if (k == 0) {
            state.output.push_back(state.currSequence);
            return;
        }
        else if (k < 0) {
            return;
        }
        
        if(i >= state.nums.size()) {
            return;
        }
        
        findCombinations(i + 1, k, state);        
        state.currSequence.push_back(state.nums[i]);
        findCombinations(i, k - state.nums[i], state);
        state.currSequence.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        State state;
        state.nums = nums;
        
        findCombinations(0, target, state);
        
        return state.output;
    }
};