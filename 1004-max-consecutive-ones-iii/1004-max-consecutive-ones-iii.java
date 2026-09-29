class Solution {
    public int longestOnes(int[] nums, int k) {
        int zero=0;
        int maxLen=0;
        int left=0;
        int n=nums.length;
        for(int right=0;right<n;right++){
           if(nums[right]==0)zero++;
           while(left<=right && zero>k){
             if(nums[left]==0)zero--;
             left++;
           }
           maxLen=Math.max(maxLen,right-left+1);
        }
        return maxLen;
    }
}