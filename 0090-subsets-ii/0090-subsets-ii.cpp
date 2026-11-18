class Solution {
public:
    void solve(vector<int>&nums,int ind,vector<int>&output,vector<vector<int>>&ans){
        ans.push_back(output);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            output.push_back(nums[i]);
            solve(nums,i+1,output,ans);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,output,ans);
        return ans;
    }
};