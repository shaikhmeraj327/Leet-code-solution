class Solution {
   public void solve(int n,StringBuilder output,List<String>ans,int ind,int open,int close){
       if(ind>=n*2){
           ans.add(output.toString());
           return;
       }
       if(open<n){
          output.append('(');
          solve(n,output,ans,ind+1,open+1,close);
          output.deleteCharAt(output.length()-1);
       }
       if(close<open){
          output.append(')');
          solve(n,output,ans,ind+1,open,close+1);
           output.deleteCharAt(output.length()-1);
       }

   }

    public List<String> generateParenthesis(int n) {

        StringBuilder output=new StringBuilder();
        List<String>ans=new ArrayList<>();
        int open=0;
        int close=0;
        solve(n,output,ans,0,open,close);
        return ans;
    }
}