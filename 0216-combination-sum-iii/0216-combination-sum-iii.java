class Solution {
   public void solve(int k,int n,List<Integer>output,List<List<Integer>>ans,int ind){
       if(n<0)return;

       if(output.size()==k && n==0){
         ans.add(new ArrayList(output));
         return;
       }
       for(int i=ind;i<=9;i++){
           if(n-i<0)break;
           output.add(i);
           solve(k,n-i,output,ans,i+1);
           output.remove(output.size()-1);
       }
   }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer>output=new ArrayList<>();
        solve(k,n,output,ans,1);
        return ans;
    }
}