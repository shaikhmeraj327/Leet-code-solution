class Solution {
    public  static void solve(int[] nums,List<Integer>output,List<List<Integer>>ans,int ind){
        
            ans.add(new ArrayList<>(output));
           
        for(int i=ind;i<nums.length;i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            output.add(nums[i]);
            solve(nums,output,ans,i+1);
            output.remove(output.size()-1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer>output=new ArrayList<>();
        List<List<Integer>> ans=new ArrayList<>();
        solve(nums,output,ans,0);
        return ans;
    }
}