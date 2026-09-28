class Solution {
   public int solve(int[] nums,int k){
      int n=nums.length;
      if(k==0)return 0;
      HashMap<Integer,Integer>map=new HashMap<>();
      int left=0;
      int total=0;
      for(int right=0;right<n;right++){
          if(map.containsKey(nums[right])){
            map.put(nums[right],map.get(nums[right])+1);  
          }
          else map.put(nums[right],1);
          while(map.size()>k){
             int count=map.get(nums[left]);
             count--;
             if(count==0)map.remove(nums[left]);
             else map.put(nums[left],count);
             left++;
          }
          total+=right-left+1;
      }
      return total;
   }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
}