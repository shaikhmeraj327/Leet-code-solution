#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<string>> ans;
    
    // Backtracking DFS from endWord to beginWord
    void dfs(string word, const string& beginWord, unordered_map<string, int>& dist, vector<string>& path) {
        if (word == beginWord) {
            path.push_back(beginWord);
            vector<string> temp = path;
            reverse(temp.begin(), temp.end()); // Reverse to get beginWord -> endWord order
            ans.push_back(temp);
            path.pop_back();
            return;
        }
        
        path.push_back(word);
        int curr_dist = dist[word];
        
        // Try all 1-character variations of the current word
        for (int i = 0; i < word.size(); ++i) {
            char temp = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == temp) continue;
                word[i] = ch;
                
                // Only transition if the neighbor is visited and lies on a shortest path
                if (dist.find(word) != dist.end() && dist[word] == curr_dist - 1) {
                    dfs(word, beginWord, dist, path);
                }
            }
            word[i] = temp; // Restore
        }
        path.pop_back(); // Backtrack
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};
        
        unordered_map<string, int> dist;
        dist[beginWord] = 0;
        
        queue<string> q;
        q.push(beginWord);
        
        // Remove start word from set to prevent backtracking to it during BFS
        wordSet.erase(beginWord); 
        
        bool found = false;
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visitedThisLevel;
            
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) {
                    found = true;
                    break;
                }
                
                string original = word;
                for (int j = 0; j < word.size(); ++j) {
                    char temp = word[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == temp) continue;
                        word[j] = ch;
                        
                        if (wordSet.find(word) != wordSet.end()) {
                            if (dist.find(word) == dist.end()) {
                                dist[word] = dist[original] + 1;
                                q.push(word);
                                visitedThisLevel.insert(word);
                            }
                        }
                    }
                    word[j] = temp; // Restore
                }
            }
            // Erase all words visited at this level from the set so they aren't reused in future levels
            for (const string& w : visitedThisLevel) {
                wordSet.erase(w);
            }
        }
        
        // If endWord was never reached
        if (dist.find(endWord) == dist.end()) return {};
        
        vector<string> path;
        dfs(endWord, beginWord, dist, path);
        return ans;
    }
};