class Solution {
public:
    void solve(vector<int>&nums,int ind,vector<int>&output,vector<vector<int>>&ans){
        if(ind>=nums.size()){
           ans.push_back(output);
           return;
        }
        output.push_back(nums[ind]);
        solve(nums,ind+1,output,ans);
        output.pop_back();
        solve(nums,ind+1,output,ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,0,output,ans);
        return ans;
    }
};