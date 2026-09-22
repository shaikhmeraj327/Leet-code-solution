class Solution {
    public void solve(int[] candidates,int target,List<Integer>output,List<List<Integer>>ans,int ind){
          if(target==0){
            ans.add(new ArrayList<>(output));
            return;
          }
          if(target<0)return ;
          for(int i=ind;i<candidates.length;i++){
             if(i>ind && candidates[i]==candidates[i-1])continue;
             if(target-candidates[i]>=0){output.add(candidates[i]);
             solve(candidates,target-candidates[i],output,ans,i+1);
             output.remove(output.size()-1);}
             
          }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<Integer>output=new ArrayList<>();
        List<List<Integer>> ans=new ArrayList<>();
        Arrays.sort(candidates);
        solve(candidates,target,output,ans,0);
        return ans;
    }
}