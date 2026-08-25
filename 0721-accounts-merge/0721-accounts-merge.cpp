#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Path compression
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    // Union by rank
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[u] = v;
                rank[v]++;
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Map: Email String -> Account ID
        unordered_map<string, int> emailToId;

        // Step 1: Group connected account indices using DSU
        for (int i = 0; i < n; i++) {
            // Note: accounts[i][0] is the owner's name, emails start from index 1
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                
                // If we've seen this email before, union current account 'i' with the previous one
                if (emailToId.count(email)) {
                    unionSet(i, emailToId[email], parent, rank);
                } else {
                    emailToId[email] = i;
                }
            }
        }

        // Step 2: Group all unique emails by their ultimate root parent account ID
        unordered_map<int, vector<string>> mergedEmails;
        for (const auto& [email, id] : emailToId) {
            int rootId = findParent(parent, id);
            mergedEmails[rootId].push_back(email);
        }

        // Step 3: Format the final output
        vector<vector<string>> ans;
        for (auto& [rootId, emails] : mergedEmails) {
            // Sort the emails alphabetically as required by the problem
            sort(emails.begin(), emails.end());
            
            // Retrieve the name associated with this component
            string name = accounts[rootId][0];
            
            // Construct the merged account: [name, email1, email2, ...]
            vector<string> mergedAccount;
            mergedAccount.push_back(name);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            
            ans.push_back(mergedAccount);
        }

        return ans;
    }
};