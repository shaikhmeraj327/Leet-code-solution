class Solution {
   public void solve(int[] candidates,int target,List<Integer>output,List<List<Integer>>ans,int ind){
        if(ind>=candidates.length){
            if(target==0){
                ans.add(new ArrayList<>(output));
            }
            return;
        }
        if(target-candidates[ind]>=0){
            output.add(candidates[ind]);
            solve(candidates,target-candidates[ind],output,ans,ind);
            output.remove(output.size()-1);
        }
        solve(candidates,target,output,ans,ind+1);
   }
      
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> output=new ArrayList<>();
        List<List<Integer>>ans=new ArrayList<>();
        solve(candidates,target,output,ans,0);
        return ans;
    }
}