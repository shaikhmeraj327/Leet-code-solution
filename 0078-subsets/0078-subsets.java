class Solution {
    public void solve(int[] nums,List<Integer>output,List<List<Integer>> ans,int ind){
        if(ind>=nums.length){
            ans.add(new ArrayList<>(output));
            return;
        }
        output.add(nums[ind]);
        solve(nums,output,ans,ind+1);
        if(output.size()>0)
         output.remove(output.size()-1);
        solve(nums,output,ans,ind+1);
        
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> output=new ArrayList<>();
        List<List<Integer>> ans=new ArrayList<>();
        solve(nums,output,ans,0);
        return ans;
    }
}