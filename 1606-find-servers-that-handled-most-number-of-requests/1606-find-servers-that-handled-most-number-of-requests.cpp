class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        
        // Count of requests handled by each server
        vector<int> count(k, 0);

        // Min-heap to store busy servers: {finish_time, server_id}
        // Using long long for finish_time to avoid any potential overflow
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> busy;

        // Set of currently available server IDs
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        for (int i = 0; i < n; ++i) {
            long long curTime = arrival[i];
            long long duration = load[i];

            // Free all servers that have finished processing by curTime
            while (!busy.empty() && busy.top().first <= curTime) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            int target = i % k;
            auto it = available.lower_bound(target);

            // If no server >= target, wrap around to the first available server
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;
            count[server]++;
            
            // Assign the request: mark server as busy and remove from available pool
            busy.push({curTime + duration, server});
            available.erase(it);
        }

        // Find the maximum number of requests handled
        int maxRequests = *max_element(count.begin(), count.end());

        // Collect all servers that handled maxRequests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};