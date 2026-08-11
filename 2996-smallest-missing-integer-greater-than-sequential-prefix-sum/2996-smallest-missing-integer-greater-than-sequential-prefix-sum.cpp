class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)maxi+=nums[i];
            else break;
        }
        unordered_set<int>set(nums.begin(),nums.end());
        while(true){
            if(set.find(maxi)==set.end())break;
            else maxi++;
        }
        return maxi;
    }
};