class Solution {
    public int removeDuplicates(int[] nums) {
        int index=1;
        int n=nums.length;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            else {
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
}