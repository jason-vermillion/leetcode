// https://leetcode.com/problems/word-ladder/
// BFS using queue
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<pair<string,int>> searchQ; // word and search depth
        
        // Cannot reach end state.
        if (words.count(endWord) == 0) return 0;
        
        searchQ.push(make_pair(beginWord, 1));
        visited.insert(beginWord);
        
        while (!searchQ.empty()) {
            pair<string,int> curr = searchQ.front();
            searchQ.pop();
            
            if (curr.first == endWord) {
                return curr.second;
            }

            // add the list of adjacent nodes
            for (int i = 0; i < curr.first.size(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    string adjWord = curr.first;
                    adjWord[i] = 'a' + j;
                    if (words.count(adjWord) > 0 && visited.count(adjWord) == 0) {
                        searchQ.push(make_pair(adjWord, curr.second + 1));
                        visited.insert(adjWord);
                    }
                }
            }
        }
        
        return 0;
        
    }
};