class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // solveing using kadans algorithm
        int n=nums.size();
        int currMax=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<n;i++){
            currMax=max(nums[i],currMax+nums[i]);
            maxSum=max(currMax,maxSum);
        }
        return maxSum;
    }
};