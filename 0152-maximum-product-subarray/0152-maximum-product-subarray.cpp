class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currMin=nums[0];
        int currMax=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(currMin,currMax);
            currMin=min(currMin*nums[i],nums[i]);
            currMax=max(currMax*nums[i],nums[i]);
            maxi=max(maxi,currMax);
        }
        return maxi;
    }
};