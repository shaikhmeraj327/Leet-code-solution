#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
private:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank, int& components) {
        u = findParent(parent, u);
        v = findParent(parent, v); // FIXED: Changed u to v here
        
        if (u != v) {
            if (rank[u] > rank[v]) {
                parent[v] = u;
            } else if (rank[u] < rank[v]) {
                parent[u] = v;
            } else {
                parent[u] = v;
                rank[v]++;
            }
            components--; // Merging two components decreases total components by 1
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n; // Initially each stone is its own component
        
        unordered_map<int, int> rows; // row -> index of first stone seen on this row
        unordered_map<int, int> cols; // col -> index of first stone seen on this col

        for (int i = 0; i < n; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            // If we've seen this row before, union current stone with the first stone of this row
            if (rows.count(r)) {
                unionSet(i, rows[r], parent, rank, components);
            } else {
                rows[r] = i;
            }

            // If we've seen this col before, union current stone with the first stone of this col
            if (cols.count(c)) {
                unionSet(i, cols[c], parent, rank, components);
            } else {
                cols[c] = i;
            }
        }

        // Maximum stones removed = total stones - remaining connected components
        return n - components;
    }
};