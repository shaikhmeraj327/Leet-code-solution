class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=1;
        int currMaxi=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])currMaxi++;
            else currMaxi=1;
            maxi=max(maxi,currMaxi);
        }
        currMaxi=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])currMaxi++;
            else currMaxi=1;
            maxi=max(maxi,currMaxi);
        }
        return maxi;
    }
};