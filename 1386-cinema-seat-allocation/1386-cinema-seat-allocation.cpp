class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> map;
        int m = reservedSeats.size();
        
        // FIXED: Loop goes up to 'm' (edges/seats size), not 'n'
        for (int i = 0; i < m; i++) {
            int ind = reservedSeats[i][0];
            int col = reservedSeats[i][1];
            map[ind].insert(col);
        }
        
        // Rows with no reserved seats can always fit exactly 2 families
        int res = (n - map.size()) * 2;
        
        for (auto p : map) {
            auto& seats = p.second;
            
            // Check possible 4-seat configurations
            bool left = !seats.count(2) && !seats.count(3) && !seats.count(4) && !seats.count(5);
            bool right = !seats.count(6) && !seats.count(7) && !seats.count(8) && !seats.count(9);
            bool mid = !seats.count(4) && !seats.count(5) && !seats.count(6) && !seats.count(7);
            
            if (left && right) {
                res += 2; // We can fit both left and right families
            } else if (left || right || mid) {
                res += 1; // We can fit at least one family
            }
        }
        
        return res;
    }
};