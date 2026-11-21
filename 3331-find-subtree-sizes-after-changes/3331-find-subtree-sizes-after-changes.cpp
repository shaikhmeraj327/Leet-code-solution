#include <vector>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<vector<int>> path_chars(26);
        
        // DFS to find the new parent for each node based on original tree
        auto findNewParents = [&](auto self, int u) -> void {
            int char_idx = s[u] - 'a';
            if (!path_chars[char_idx].empty()) {
                newParent[u] = path_chars[char_idx].back();
            }
            
            path_chars[char_idx].push_back(u);
            for (int v : adj[u]) {
                self(self, v);
            }
            path_chars[char_idx].pop_back();
        };
        
        findNewParents(findNewParents, 0);

        // Build the new tree
        vector<vector<int>> newTree(n);
        for (int i = 1; i < n; ++i) {
            newTree[newParent[i]].push_back(i);
        }

        // DFS to calculate subtree sizes in the new tree
        vector<int> ans(n);
        auto calculateSubtreeSize = [&](auto self, int u) -> int {
            int sz = 1;
            for (int v : newTree[u]) {
                sz += self(self, v);
            }
            return ans[u] = sz;
        };

        calculateSubtreeSize(calculateSubtreeSize, 0);
        return ans;
    }
};