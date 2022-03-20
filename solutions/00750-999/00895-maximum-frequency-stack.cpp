// https://leetcode.com/problems/maximum-frequency-stack/
// 895. Maximum Frequency Stack
class FreqStack {
public:
    unordered_map<int, int> freq; // count of each val
    unordered_map<int, stack<int>> freqItems; // stack of vals for each frequency
    int maxFreq;
    
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        freqItems[freq[val]].push(val);
    }
    
    int pop() {
        int val = freqItems[maxFreq].top();
        freqItems[maxFreq].pop();
        freq[val]--;
        
        if (freqItems[maxFreq].size() == 0) {
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */