class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer>set=new HashSet<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            set.add(nums[i]);
        }
        int maxLen=0;
        for(int count:set){
            
            if(!set.contains(count-1)){
               int len=1;
               count++;
               while(set.contains(count)){
                  len++;
                  count++;
               }
               maxLen=Math.max(maxLen,len);
            }
        }
        return maxLen;
    }
}