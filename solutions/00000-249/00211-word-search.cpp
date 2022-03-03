/** https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
struct TrieNode {
    TrieNode* children[26];
    bool isEOW = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEOW = false;
    }
};
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
public:
    void addWord(string word) {
        TrieNode* curr = root;
        for (auto c : word) {
            int i = c - 'a';
            if (curr -> children[i] == NULL) {
                curr -> children[i] = new TrieNode();
            }
            curr = curr -> children[i];
        }
        curr -> isEOW = true;
    }

public:
    bool search(string word) {
        return innerSearch(word, root);
    }
    
    bool innerSearch(string word, TrieNode* curr) {
        int len = word.size();
        bool isMatch = true;
        
        for (int i = 0; i < len; i++) {
            char c = word[i];
            if (c == '.') {
                string newSearch = word.substr(i+1);
                for (auto node : curr -> children) {
                    if (node != nullptr && innerSearch(newSearch, node)) {
                        return true;
                    }
                }
                return false;
            }
            else if (curr -> children[c - 'a'] == NULL) {
                return false;
            }
            
            curr = curr -> children[c - 'a'];
        }
        
        if (curr == nullptr || curr -> isEOW == false) {
            isMatch = false;
        }
        
        return isMatch;
    }
};

