// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// 703. Kth Largest Element in a Stream
class KthLargest {
public:
    int k;
    multiset<int> ms;
    
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for (auto val : nums) {
            this -> ms.insert(val);
        }
    }
    
    int add(int val) {
        multiset<int>::iterator it;
        int result;
        
        this -> ms.insert(val);
                
        it = this -> ms.end();
        for (int i = 0; i < this -> k; ++i) {
            it--;
        }
        result = *it;
        
        return result;
    }
    
    void printArr(multiset<int>& arr) {
        multiset<int>::iterator it;
        int i = 0;
        cout << "[";
        for (it = this -> ms.begin(); it != this -> ms.end(); ++it) {
            if (i > 0) {
                cout << ",";
            }
            cout << *it;
            i++;
        }
        cout << "]\n";
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */