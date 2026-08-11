class Solution {
public:
    vector<int>solve(int row){
        int num=1;
        vector<int>res;
        res.push_back(num);
        for(int col=1;col<row;col++){
            num=num*(row-col)/col;
            res.push_back(num);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};