#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build the Adjacency List
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adjList[u].push_back({v, w});
        }
        
        // 2. cost array to store minimum cost to each node
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        
        // Queue stores: {stops, {node, current_cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            int stops = temp.first;
            int u = temp.second.first;
            int c = temp.second.second;
            
            // If we have taken more than K stops, we cannot use this path to go further
            if (stops > k) continue;
            
            for (auto p : adjList[u]) {
                int v = p.first;
                int cs = p.second;
                
                // If we find a cheaper cost to reach 'v' with 'stops' <= K
                if (c + cs < cost[v]) {
                    cost[v] = c + cs;
                    q.push({stops + 1, {v, cost[v]}});
                }
            }
        }
        
        // FIXED: Return the cost to 'dst', not 'n-1'
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};