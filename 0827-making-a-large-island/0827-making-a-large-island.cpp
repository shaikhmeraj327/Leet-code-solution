#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Path compression
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    // Union by size (rather than rank)
    void unionSet(int u, int v, vector<int>& parent, vector<int>& size) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u != v) {
            // Attach u under v, and add u's size to v's size
            parent[u] = v;
            size[v] += size[u];
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int total_cells = n * n;
        
        vector<int> parent(total_cells);
        vector<int> size(total_cells, 0);
        
        // 1. Initialize DSU: each '1' starts as its own component of size 1
        for (int i = 0; i < total_cells; i++) {
            parent[i] = i;
            int r = i / n;
            int c = i % n;
            if (grid[r][c] == 1) {
                size[i] = 1;
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        // 2. Union adjacent existing islands
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int u = r * n + c;
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dx[i];
                        int nc = c + dy[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int v = nr * n + nc;
                            unionSet(u, v, parent, size);
                        }
                    }
                }
            }
        }

        // 3. Find the largest island size without flipping any 0 (baseline)
        int max_island = 0;
        for (int i = 0; i < total_cells; i++) {
            if (grid[i / n][i % n] == 1) {
                max_island = max(max_island, size[findParent(parent, i)]);
            }
        }

        // 4. Try flipping each 0 to 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    // Use a set to collect unique adjacent island roots
                    unordered_set<int> unique_roots;
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dx[i];
                        int nc = c + dy[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int neighbor_id = nr * n + nc;
                            unique_roots.insert(findParent(parent, neighbor_id));
                        }
                    }
                    
                    // Total size if we flip grid[r][c] is 1 + sum of adjacent unique island sizes
                    int current_island_size = 1;
                    for (int root : unique_roots) {
                        current_island_size += size[root];
                    }
                    max_island = max(max_island, current_island_size);
                }
            }
        }

        return max_island;
    }
};