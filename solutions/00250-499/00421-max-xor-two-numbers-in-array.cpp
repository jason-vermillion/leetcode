class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0;
        int best = 0;
        int val = 0;
        Trie* t = new Trie();
        
        // Trie for all nums
        for (auto& num : nums) {
            t -> insert(num);
        }
        
        // use the trie to find the highest xor sum.
        for (auto& num : nums) {
            best = t -> findMaxXor(num);
            val = num ^ best;
            if (val > max) {
                max = val;
            }
        }
        
        return max;
    };
    
    struct Trie {
        public:
            Trie* nodes[2];
        public:
            void insert(int num) {
                Trie* curNode = this;
                
                for (int i = 31; i >= 0; i--) {
                    int bit = (num >> i) & 1;
                    if (curNode -> nodes[bit] == NULL) {
                        curNode -> nodes[bit] = new Trie();
                    }
                    curNode = curNode -> nodes[bit];
                }
            }
        public:
            int findMaxXor(int num) {
                int max = 0;
                Trie* curNode = this;
                
                for (int i = 31; i >= 0; i--) {
                    int bit = (num >> i) & 1;
                    if (curNode -> nodes[!bit] != NULL) {
                        curNode = curNode -> nodes[!bit];
                        max += (!bit << i);
                    }
                    else {
                        curNode = curNode -> nodes[bit];
                        max += (bit << i);
                    }
                }
                return max;
            }
        public:
            Trie() {
                nodes[0] = NULL;
                nodes[1] = NULL;
            }
    };
};