class Solution {
public:
    void solve(vector<int>&candidates,int ind,int target,vector<int>&output,vector<vector<int>>&ans){
       if(target<0)return;
       if(target==0){
          ans.push_back(output);
          return;
       } 
       for(int i=ind;i<candidates.size();i++){
           if(i>ind && candidates[i]==candidates[i-1])continue;
           if(target-candidates[i]>=0){
              output.push_back(candidates[i]);
              solve(candidates,i+1,target-candidates[i],output,ans);
              output.pop_back();
           }
       }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>output;
        vector<vector<int>>ans;
        int ind=0;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ind,target,output,ans);
        return ans;
    }
};