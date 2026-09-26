import java.util.*;
class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
        int maxi=-1000000000;
        int currMax=-1000000000;
        for(int i=0;i<n;i++){
            currMax=Math.max(nums[i],currMax+nums[i]);
            maxi=Math.max(currMax,maxi);
        }
        return maxi;
    }
}