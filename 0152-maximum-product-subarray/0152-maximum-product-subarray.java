class Solution {
    public int maxProduct(int[] nums) {
        int n=nums.length;
        int currMin=nums[0];
        int currMax=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int temp=currMin;
                currMin=currMax;
                currMax=temp;
            }
            currMin=Math.min(currMin*nums[i],nums[i]);
            currMax=Math.max(currMax*nums[i],nums[i]);
            maxi=Math.max(maxi,currMax);
        }
        return maxi;
    }
}