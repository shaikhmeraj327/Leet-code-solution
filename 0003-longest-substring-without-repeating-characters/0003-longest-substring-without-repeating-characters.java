class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] freq=new int[256];
        int maxLen=0;
        int left=0;
        int n=s.length();
        for(int right=0;right<n;right++){
           freq[s.charAt(right)]++;
           while(left<right && freq[s.charAt(right)]>1){
              freq[s.charAt(left)]--;
              left++;
           }
           maxLen=Math.max(right-left+1,maxLen);
        }
        return maxLen;
    }
}