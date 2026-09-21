class Solution {
public:
    void solve(vector<int>&nums,vector<int>&output,vector<vector<int>>&ans,int ind){
        if(ind>=nums.size()){
            ans.push_back(output);
            return;
        }
        // include
        output.push_back(nums[ind]);
        solve(nums,output,ans,ind+1);
        output.pop_back();
        solve(nums,output,ans,ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        solve(nums,output,ans,0);
        return ans;
    }
};