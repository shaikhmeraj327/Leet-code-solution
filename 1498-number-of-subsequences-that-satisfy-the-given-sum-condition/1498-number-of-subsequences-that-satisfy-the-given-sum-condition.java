class Solution {
    
    public int numSubseq(int[] nums, int target) {
        long m=1000000007;
        int n=nums.length;
        long[] power=new long[n];
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%m;
        }
        int left=0;
        int right=n-1;
        long ans=0;
        Arrays.sort(nums);
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans=(ans+power[right-left])%m;
                left++;
            }
            else right--;
        }
        return (int) ans;
    }
}