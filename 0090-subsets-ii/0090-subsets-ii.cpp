class Solution {
public:
   void solve(vector<int>&nums,vector<int>&output,vector<vector<int>>&ans,int index,int n){
        
            ans.push_back(output);
            
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1])continue;
            output.push_back(nums[i]);
            solve(nums,output,ans,i+1,n);
            output.pop_back();
        }
   }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>output;
        vector<vector<int>>ans;
        solve(nums,output,ans,0,n);
        return ans;
    }
};