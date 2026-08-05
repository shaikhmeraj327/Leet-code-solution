#include <vector>
#include <cmath>

using namespace std;

class TreeAncestor {
    // up[node][j] stores the (2^j)-th ancestor of 'node'
    vector<vector<int>> up;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        // Calculate the maximum power of 2 needed (log2 of n)
        LOG = log2(n) + 1;
        up.assign(n, vector<int>(LOG, -1));

        // Base case: The 2^0 (1st) ancestor is the direct parent
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Fill the sparse table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1) {
                    // The 2^j ancestor is the 2^(j-1) ancestor of the 2^(j-1) ancestor
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            // Check if the j-th bit of k is set
            if ((k >> j) & 1) {
                node = up[node][j];
                // If we go beyond the root, return -1
                if (node == -1) break;
            }
        }
        return node;
    }
};