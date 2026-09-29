class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int n=nums.length;
        int count=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)count++;
            if(count==k)total++;
            int rem=count-k;
            if(map.containsKey(rem)){
                total+=map.get(rem);
            }
            if(map.containsKey(count)){
                map.put(count,map.get(count)+1);
            }
            else map.put(count,1);
        }
        return total;
    }
}