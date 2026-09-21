class Solution {
   public void solve(int n,List<String>ans,StringBuilder output,int ind){
      if(ind>=n){
        ans.add(output.toString());
        return;
      }
      if(output.isEmpty() || output.charAt(output.length()-1)!='0'){
         output.append('0');
         solve(n,ans,output,ind+1);
         output.deleteCharAt(output.length()-1);
      }
      output.append('1');
      solve(n,ans,output,ind+1);
      output.deleteCharAt(output.length()-1);
   }

    public List<String> validStrings(int n) {
        List<String> ans=new ArrayList<>();
        StringBuilder output=new StringBuilder();
        solve(n,ans,output,0);
        return ans;
    }
}